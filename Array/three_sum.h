#pragma once
#ifndef THREE_SUM_H
#define THREE_SUM_H

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;


/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ?
Find all unique triplets in the array which gives the sum of zero.

Note :
Elements in a triplet(a, b, c) must be in non - descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.

For example, given array S = { -1 0 1 2 -1 -4 },

A solution set is :
(-1, 0, 1)
(-1, -1, 2)

as we know two-sum requires O(n) so we can create
an 3-sum algorithm with n * O(n) = O(n^2)

wekipedia pesudo algorithm:
sort(S);
for i=0 to n-3 do
	a = S[i];
	start = i+1;
	end = n-1;
	while (start < end) do
		b = S[start];
		c = S[end];
		if (a+b+c == 0) then
			output a, b, c;
			// Continue search for all triplet combinations summing to zero.
			start = start + 1
			end = end - 1
		else if (a+b+c > 0) then	
			end = end - 1;
		else
			start = start + 1;
		end
	end
end
*/

vector<string> three_sum(vector<int>& array, int target)
{
	vector<string> sol;

	std::sort(array.begin(), array.end());
	for (int i = 0; i < array.size() - 2; ++i) {
		int a = array[i];
		int start = i + 1;
		int end = array.size() - 1;

		while (start < end) {
			int b = array[start];
			int c = array[end];
			if ((a + b + c - target) == 0) {
				std::ostringstream oss;
				oss << "(" << a << ")+(" << b << ")+(" << c << ")=" << target;
				sol.push_back(oss.str());
				start++;
				end--;
			}
			else if ( (a + b + c - target) > 0)
				end = end --;
			else
				start++;
		}
	}
	return sol;
}

#endif