#pragma once
#include <vector>
#include "../test.h"

using namespace std;
/*
given an sorted array with duplicate:

{0, 1, 2, 2, 3, 4, 5, 5 ,5, 6 ,7}

target:5 

return the starting position and end positon of 5,
such as 6 and 8 respectively

If not found, simply return -1

key point is to make it into 3 sections, left, midle and right
midle is the trick part - once you hit at the mid section
also need to get left and right boundaries
*/


std::vector<int> SortedArrayRangeSearch(int* array, int target, int start, int end)
{
	std::vector<int> sol{-1,-1};

	if (array == nullptr || start > end) 
		return sol;

	if (start == end) {
		if (array[start] == target) {
			sol[0] = sol[1] = start;
		}
		return sol;
	}

	int mid = start + (end - start) / 2;

	if (array[mid] == target) {
		sol[0] = sol[1] = mid;
		auto left  = SortedArrayRangeSearch(array, target, 0, mid-1);
		auto right = SortedArrayRangeSearch(array, target, mid + 1, end);
		sol[0] = (left[0] != -1) ? left[0] : sol[0];
		sol[1] = (right[1] != -1) ? right[1] : sol[1];
	}
	else if(array[mid] < target)
		sol = SortedArrayRangeSearch(array, target, mid + 1, end);
	else if(array[mid] > target)
		sol = SortedArrayRangeSearch(array, target, start, mid-1);

	return sol;
}



#define TEST_RANGE(e1, a1, e2, a2) \
	TEST_INT(e1, a1); \
	TEST_INT(e2, a2); \

void testSortedArrayRangeSearch()
{
	vector<int> sol;
	int array1[1] = { 3 };

	sol = SortedArrayRangeSearch(array1, -1, 0, 0);
	TEST_RANGE(-1, sol[0], -1, sol[1]);

	sol = SortedArrayRangeSearch(array1, 3, 0, 0);
	TEST_RANGE(0, sol[0], 0, sol[1]);

	int array[17] = { 0,1,2,3,3,3,4,4,5,6,7,7,7,7,7,8,9 };

	sol = SortedArrayRangeSearch(array, -1, 0, 16);
	TEST_RANGE(-1, sol[0], -1, sol[1]);

	sol = SortedArrayRangeSearch(array, 0, 0, 16);
	TEST_RANGE(0, sol[0], 0, sol[1]);

	sol = SortedArrayRangeSearch(array, 6, 0, 16);
	TEST_RANGE(9, sol[0], 9, sol[1])

		sol = SortedArrayRangeSearch(array, 9, 0, 16);
	TEST_RANGE(16, sol[0], 16, sol[1]);

	sol = SortedArrayRangeSearch(array, 3, 0, 16);
	TEST_RANGE(3, sol[0], 5, sol[1]);

	sol = SortedArrayRangeSearch(array, 4, 0, 16);
	TEST_RANGE(6, sol[0], 7, sol[1]);

	sol = SortedArrayRangeSearch(array, 7, 0, 16);
	TEST_RANGE(10, sol[0], 14, sol[1]);

}