#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Swap sort: 
precondition: 
integer element 
contains n elements equivalent the set of their indices

index: 0 1 2 3 4
item:  4 2 1 3 0

run O(n)
*/

void swapSort(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] != i) {
			int temp = vec[i];
			vec[temp] = temp;
			vec[i] = i;
		}
	}
}

void testSwapSort()
{
	vector<int> vec = { 4,3,2,1,0,6,5 };
	swapSort(vec);
	for (int & i : vec) {
		cout << i << " ";
	}
	cout << endl;
}


