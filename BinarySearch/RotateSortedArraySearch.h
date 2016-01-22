#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
if there is duplicate, you cannot do better than simple O(n) solution
*/

int search(vector<int>& nums, int target) {
	if (nums.empty()) return -1;
	int l = 0;
	int u = nums.size() - 1;
	while (l <= u) {
		int m = l + (u - l) / 2;
		if (nums[m] == target) return m;
		else if (nums[l] <= nums[m]) {    //equal is needed; if size=2 then l = m
			if (target > nums[m])
				l = m + 1;
			else if (target >= nums[l])
				u = m - 1;
			else
				l = m + 1;
		}
		else if (target < nums[m])
			u = m - 1;
		else if (target <= nums[u])
			l = m + 1;
		else
			u = m - 1;
	}
	return -1;
}



/* 
now search for the minimum for rotated sorted array
*/


int searchMin(vector<int>& nums)
{
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r) {
		if (l == r) return nums[l];
		int m = l + (r - l) / 2;
		if (nums[l] <= nums[m]) {
			if (nums[r] < nums[m])
				l = m + 1;
			else
				r = m - 1;
		}
		else {
			int n = l + (m - l) / 2;
			if (nums[m] > nums[n])
				r = n;
			else
				l = n+1;
		}
	}
	return nums[l];
}


void testSearchMin()
{
	vector<int> v = {3,1,2};
	cout << searchMin(v) << endl;
}