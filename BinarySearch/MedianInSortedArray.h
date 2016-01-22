#pragma once
#include "../test.h"
#include <iostream>
#include <vector>

using namespace std;

/*
problem: find median among two sorted arrays

The catch-up is this: 
For two arrays whose length are m, n respectively
median is actually the (m+n/2)_th element if m+n is odd
or the avg of (m+n)/2_th + (m+n)/2+1 _th  if m+n is even

so each time we can cut-off k/2 element, and the k_th element becomes k-k/2_th

since int division in C++ is floor,

we let small array cut-off k/2
and large array cut-off k - k/2

if one array is trimmed to zero, then the k-th element resides on larger array

if k=1, then k resides on either smaller array or larger array (depends on which element is smaller)
*/


/*
s, l: smaller array and larger array (in size)
s0, l0: starting indices
k: the kth element we want to find
*/
double findKth(const vector<double>& s, int s0, const vector<double>& l, int l0, int k)
{
	int slen = s.size() - s0;
	int llen = l.size() - l0;
	
	if (slen > llen)
		return findKth(l, l0, s, s0, k);

	if (slen == 0) {
		return l[l0 + k - 1];
	}
	
	if (k == 1) {
		return (s[s0] > l[l0]) ? l[l0] : s[s0];
	}

	//set to small array size if k/2 is larger than its size
	//which is equivalent to trim down small array
	int sCut = ((k / 2) > slen) ? slen : (k / 2);
	int lCut = k - sCut;

	int sIndex = s0 + sCut - 1;
	int lIndex = l0 + lCut - 1;

	if (s[sIndex] <= l[lIndex])
		return findKth(s, s0 + sCut, l, l0, k - sCut);
	else
		return findKth(s, s0, l, l0 + lCut, k - lCut);
}

double findMedian(const vector<double>& v1, const vector<double>& v2)
{
	int total = v1.size() + v2.size();
	if (total % 2 == 1)
		return findKth(v1, 0, v2, 0, total / 2 + 1);
	else
		return (findKth(v1, 0, v2, 0, total / 2) + findKth(v1, 0, v2, 0, total / 2 + 1)) / 2.0;
}

void test4()
{
	double delta = 1E-8;
	double actual;

	vector<double> v1 = { 1 };
	vector<double> v2 = { 1,2,3,4,5,6 };
	actual = findMedian(v1, v2);
	TEST_DOUBLE(3, actual, delta);

	vector<double> v3 = { 1,2,3,3,5,6,7,8 };
	vector<double> v4 = { 1,2,3,4,5,7,8,9 };
	actual = findMedian(v3, v4);
	TEST_DOUBLE(4.5, actual, delta);

	vector<double> v5 = { 1,2 };
	vector<double> v6 = { 1,2,3 };
	actual = findMedian(v5, v6);
	TEST_DOUBLE(2, actual, delta);

	vector<double> v7;
	vector<double> v8 = { 2,3 };
	actual = findMedian(v7, v8);
	TEST_DOUBLE(2.5, actual, delta);

	vector<double> v9 = { 1,2 };
	vector<double> v10 = { 1,2 };
	actual = findMedian(v9, v10);
	TEST_DOUBLE(1.5, actual, delta);


	vector<double> v11 = { 1,1 };
	vector<double> v12 = { 1,2 };
	actual = findMedian(v11, v12);
	TEST_DOUBLE(1, actual, delta);


	vector<double> v13 = { 1,2 };
	vector<double> v14 = { 1,1 };
	actual = findMedian(v13, v14);
	TEST_DOUBLE(1, actual, delta);

	vector<double> v15 = { 2 };
	vector<double> v16 = { 1,3,4 };
	actual = findMedian(v15, v16);
	TEST_DOUBLE(2.5, actual, delta);

	vector<double> v17 = { 1,2,6 };
	vector<double> v18 = { 3,4,5 };
	actual = findMedian(v17, v18);
	TEST_DOUBLE(3.5, actual, delta);

	vector<double> v19 = { 8 };
	vector<double> v20 = { 1,2,3,4,5,6,7 };
	actual = findMedian(v19,v20);
	TEST_DOUBLE(4.5, actual, delta);

	vector<double> v21 = { 1, 2, 3, 4, 10 };
	vector<double> v22 = { 5,6,7,8,9 };
	actual = findMedian(v21, v22);
	TEST_DOUBLE(5.5, actual, delta);
}
