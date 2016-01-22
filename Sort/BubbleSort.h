#pragma once
#include <vector>
#include <iostream>

using namespace std;

void bubbleSort(vector<int>& v) 
{
	int n = v.size();
	while (n > 0) {
		int n1 = 0;
		for (int i = 1; i < n; ++i) {
			if (v[i - 1] > v[i]) {
				cout << "swap " << v[i - 1] << " and " << v[i] << endl;
				int tmp = v[i-1];
				v[i - 1] = v[i];
				v[i] = tmp;
				 n1 = i;
			}
			for (auto i : v)
				cout << i << " ";
			cout << endl;
		}
		n = n1;
		cout << "n is " << n << endl;
	}
}

void testBubbleSort()
{
	vector<int> v = {5,0,3,2,1,4,8,7,6,9};

	bubbleSort(v);
}