#pragma once
#include "../test.h"

int binarySearch(int* array, int target, int start, int end)
{
	if (array == nullptr || start > end)
		return -1;
	if (start == end) {
		if (array[start] == target)
			return start;
		else
			return -1;
	}

	int mid = start + (end - start) / 2;
	if (array[mid] < target)
		return binarySearch(array, target, mid + 1, end);
	else
		return binarySearch(array, target, start, mid);
}

//norecursive
int binarySearch2(int * array, int target, int start, int end)
{
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (array[mid] == target) return mid;
		if (array[mid] < target)
			start = mid+1;
		else
			end = mid;
	}
	if (array[start] == target)
		return start;
	return -1;
}


void test(int expect, int * array, int target, int start, int end, bool recursive)
{
	if (recursive)
		TEST_INT(expect, binarySearch(array, target, start, end));
	else
		TEST_INT(expect, binarySearch2(array, target, start, end));
}


void testBinarySearch()
{
	int array[11] = { 0,1,2,3,4,5,6,7,8,9,10 };


	test(10, array, 10, 0, 10, true);
	test(9, array, 9, 0, 10, true);
	test(1, array, 1, 0, 10, true);
	test(0, array, 0, 0, 10, true);
	test(5, array, 5, 0, 10, true);
	test(-1, array, -1, 0, 10, true);

	test(10, array, 10, 0, 10, false);
	test(9, array, 9, 0, 10, false);
	test(1, array, 1, 0, 10, false);
	test(0, array, 0, 0, 10, false);
	test(5, array, 5, 0, 10, false);
	test(-1, array, -1, 0, 10, false);

	int array1[1] = { 3 };
	test(0, array1, 3, 0, 0, true);
	test(-1, array1, 4, 0, 0, true);

	test(0, array1, 3, 0, 0, false);
	test(-1, array1, 4, 0, 0, false);
}