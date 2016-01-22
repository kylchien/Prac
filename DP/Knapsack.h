#pragma once
#include <iostream>
#include <vector>

using namespace std;

int my_max(int a, int b) { return (a > b) ? a : b; }

void knapsack(const vector<int>& value, const vector<int>& weight, const int targetWeight)
{
	if (value.empty() || weight.empty() || targetWeight == 0) return;

	int r = value.size() + 1;
	int w = targetWeight + 1;

	//construct a (r x w) 2d array
	vector<vector<int>> table(r);
	for (int i = 0; i < r;++i) {
		vector<int> vec(w, 0);
		table[i] = vec;
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < w; ++j) {
			
			if (i == 0 || j == 0)					//base case
				table[i][j] = 0;
			else if (weight[i-1] > j)				//bearable load is less than the item's weight
				table[i][j] = table[i-1][j];        //cannot take the item
			else {
				table[i][j] = my_max(
					table[i - 1][j],
					value[i-1]+ table[i][targetWeight-weight[i-1]]);
			}

		}
	}

	for (int i = 0; i < r;++i) {
		for (int j = 0; j < w;++j) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}


