#pragma once
#include <vector>
#include <iostream>

using namespace std;

void insertionSort(vector<int>& v)
{
	for (int i = 1; i<v.size(); ++i) {
		int x = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > x) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = x;
	}
}

void testInsertionSort()
{
	vector<int> v = { 1,3,5,7,9,2,4,6,8,0 };
	insertionSort(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}


/*
4 3 2 1 5
4 [3] 2 1 5
3 4 2 1 5
3 4 [2] 1 5
2 3 4 1 5
2 3 4 [1] 5
1 2 3 4 5
1 2 3 4 [5]
*/