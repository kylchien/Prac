#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/interleaving-string/

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


dynamic programming (DP), which usually have much less complexity. In this problem, a 2D DP is more suitable.  
As usual, the typical way of solving dp is to find the state, and the optimal function

A[i][j] = (s3[i+j]==s1[i]  && match[i-1][j])  || (s3[i+j] ==s2[j] && match[i][j-1])
*/

bool isInterleave(string s1, string s2, string s3)
{
	int size1 = s1.size();
	int size2 = s2.size();

	if (size1 + size2 != s3.size()) return false;
	//if (size1 == 0 && size2 == 0 && s3.empty()) return true;

	vector<vector<bool>> match(size1+1, vector<bool>(size2+1, false));
	match[0][0] = true;

	for (int i = 1; i <= size1;++i)
		match[i][0] = (s1[i - 1] == s3[i - 1]) && (match[i - 1][0]);

	for (int i = 1; i <= size2;++i)
		match[0][i] = (s2[i - 1] == s3[i - 1]) && (match[0][i-1]);

	for (int i = 1; i <= size1; ++i) {
		for (int j = 1; j <= size2; ++j) {
			bool c1 = (s3[i + j - 1] == s1[i-1]) && (match[i-1][j]);
			bool c2 = (s3[i + j - 1] == s2[j-1]) && (match[i][j-1]);
			match[i][j] = c1 || c2;
		}
	}

	for (int i = 0; i < size1 + 1;++i) {
		for (int j = 0; j < size2 + 1; ++j) {
			cout << match[i][j] << " ";
		}
		cout <<endl;
	}

	return match[size1][size2];
}


void testIsInterleave()
{
	
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout << isInterleave(s1, s2, s3) << endl;
	/*
	string s1 = "135";
	string s2 = "2";
	string s3 = "1235";
	cout << isInterleave(s1, s2, s3) << endl;
	*/
}