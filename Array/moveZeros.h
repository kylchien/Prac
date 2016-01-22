#pragma once
#include <vector>
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/move-zeroes/

Given an array nums, write a function to move all 0's to the end of it while 
maintaining the relative order of the non-zero elements. No extra copy of 
array allows.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
nums should be [1, 3, 12, 0, 0].

catch: This is more a problem to C++, since vector supports iterator erase but index-delete.
We need to do the swap in-place.
*/

inline void swap(int& i, int& j)
{
	int tmp = i;
	i = j;
	j = tmp;
}

void moveZeroes(vector<int>& nums) 
{
	int n = nums.size();
	if( n<=1) return;

	//current non-zero index, and scanned index
	int cur =0, scan = 0;

	while(scan < n){
		if(nums[scan] !=0){
			swap(nums[cur], nums[scan]);
		cur++;
	}
	scan++;
}


void testMoveZeros()
{
	vector<int> v = { 0,0,1,0,2,0,3,0 };

	vector<int>::iterator iter = v.begin();

	while (iter != v.end()) {
		if (*iter == 0) {
			v.erase(iter);
			iter = v.begin();
		}
		else
			iter++;
	}

	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
