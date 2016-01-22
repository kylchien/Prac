#pragma once
#include <vector>
#include <iostream>

using namespace std;

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4], 
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

catch: since it asks for the largest sum but not the actual indices,
we can store the max sum info only and scan the entire array.
If the sum is smaller than next element, simply drop it and 
start recording from current position.
*/

int MAX(int a, int b) { return (a>b) ? a : b; }

int maxSubArray(vector<int> nums)
{
	int newsum = nums[0];   //current sum
	int maxSum = nums[0];   //best sum we have
	for (int i = 1;i < nums.size();i++) {
		newsum = MAX(newsum + nums[i], nums[i]);
		maxSum = MAX(maxSum, newsum);
	}
	return maxSum;
}
