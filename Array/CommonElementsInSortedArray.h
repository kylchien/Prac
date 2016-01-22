#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/*
my google interview question

two sorted array, say in ascending order, find the common elements, output prints duplicates only once

for example:

1 2 3 4
1 1 2 3 5

output 1 2 3

key words: sorted, duplicate only once

thought: using two indice variable to track the scanning progress; 
if one scans larger element, increment the other scan index 

O(max(m,n)) where m,n are the size of the array respectively
*/

vector<int> commonElements(const vector<int>& sorted1, const vector<int>& sorted2)
{
	vector<int> sol;
	if (sorted1.empty() || sorted2.empty()) return sol;
	
	int scan1 = 0;
	int scan2 = 0;

	for (int i = 0; i < sorted1.size(); ++i){
		//scan to one of the end already
		if (scan1 >= sorted1.size() || scan2 >= sorted2.size()) 
			break;

		int item1 = sorted1[scan1];
		int item2 = sorted2[scan2];

		if (item1 > item2) {
			scan2++;
		}
		else if (item1 < item2) {
			scan1++;
		}
		else{
			sol.push_back(item1);
			++scan1;
			++scan2;
		}
	}

	return sol;
}

/*
now, how about you have mutiple sorted arrays?

1 1 2 2 3 3 
1 2 3 4 4
2 4

output 2

my thoought:
find the max in current scan, if other scanned elements are smaller
than the max, increase the scanning index until its element is equal 
or larger than the max; if it is larger, it shall be the new max and 
update the max and which array contains this max accordingly; if it is equal,
we update count; there is a common element iff the count == total number 
of arrays (and thus add to solution); once we have new max, we need to 
start the scan from array 1 to array n, and looking their correspoinding 
scanning indices; 
*/
vector<int> commonElements(const vector<vector<int>>& vec)
{
	vector<int> sol;

	int size = vec.size();
	if (size == 0) return sol;

	vector<int> scan(size,0);
	int max = vec[0][0];
	int maxVec = 0;

	while (1)
	{
		int count = 0;

		//cout << "new for loop\n";
		for (int i = 0; i < size;++i){
			while (vec[i][scan[i]] < max && i != maxVec) {
				scan[i]++;
				//cout << "scan[" << i << "] now is " << scan[i] << "\n";
				if (scan[i] >= vec[i].size()) {
					//cout << "terminate one\n";
					return sol;
				}
			}

			if (vec[i][scan[i]] == max) {
				//cout << "vec[" << i << "][scan[" << i << "]]=" << max << ", so count++" << endl;
				count++;
			}
			else if (vec[i][scan[i]] >max) {
				max = vec[i][scan[i]];
				maxVec = i;
				//cout << "max is now " << max << ", and maxVec=" << maxVec << endl;
				break;
			}
		}

		if (count == size) {
			sol.push_back(max);
			//cout << "push " << max << " into solution" << endl;
			while (vec[maxVec][scan[maxVec]] == max) {
				scan[maxVec]++;
				if (scan[maxVec] >= vec[maxVec].size()) {
					//cout << "terminate two\n";
					return sol;
				}
			}

			max = vec[maxVec][scan[maxVec]];
			//cout << "max is now " << max << ", and maxVec=" << maxVec << endl;
		}
	}
	return sol;
}


bool testSortedVec(const vector<int>& v1, const vector<int>& v2)
{
	if (v1.size() != v2.size())
		return false;
	for (int i = 0; i < v1.size(); ++i)
		if (v1[i] != v2[i]) return false;
	return true;
}


void testCommonElements()
{
	using ARRAY = vector<int>;

	vector<int> v1 = {1,1,2,3,4,4,5,6,7};
	vector<int> v2 = {1,2,2,5,8,8};
	vector<int> expect = {1,2,5};
	vector<int> actual = commonElements(v1, v2);
	assert(testSortedVec(expect, actual));

	
	vector<ARRAY> v3;
	v3.push_back(v1);
	v3.push_back(v2);
	actual = commonElements(v3);
	assert(testSortedVec(expect, actual));
	

	ARRAY v4 = {1, 2, 3, 4, 5, 6, 7, 8};
	ARRAY v5 = {1,1,2,2,3,3,8};
	ARRAY v6 = {0,2,8};
	ARRAY v7 = {2, 5, 6, 7,8};
	ARRAY v8 = {1,2,3,5,7,8};
	ARRAY v9 = {2,4,6,8};

	vector<ARRAY> v10;
	v10.push_back(v4); v10.push_back(v5); v10.push_back(v6); 
	v10.push_back(v7); v10.push_back(v8); v10.push_back(v9);
	actual = commonElements(v10);
	expect = {2,8};
	assert(testSortedVec(expect, actual));

	//for (int i : actual)
	//	cout << i << " ";
	//cout << endl;

	cout << "test pass!" << endl;
}



