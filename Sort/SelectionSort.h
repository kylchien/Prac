#pragma once
#include <vector>
#include <iostream>

using namespace std;

void selectionSort(vector<int>& v)
{
	int n = v.size();
	if (n <= 1) return;

	//i is the current sorted boundary
	//j is the starting search range
	for (int i = 0; i < n - 1; ++i) {
		int minPos = i;
		for (int j = i + 1; j < n; ++j) {
			if (v[minPos] > v[j]) {
				minPos = j;
			}
		}

		//swap the positions to put next min into i
		if (minPos != i) {
			int tmp = v[i];
			v[i] = v[minPos];
			v[minPos] = tmp;
		}
	}
}

void testSelectionSort()
{
	vector<int> v = {1,7,8,4,3,0,5,2,6,9};
	selectionSort(v);

	for (auto i : v)
		cout << i << " ";
	cout << endl;
}


/*
4 3 2 1 5
[4] 3 2 1 5
[1] 3 2 4 5
1 [3] 2 4 5
1 [2] 3 4 5
1 2 [3] 4 5
1 2 3 [4] 5
1 2 3 4 [5]
*/