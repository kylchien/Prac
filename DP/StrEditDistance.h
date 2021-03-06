#pragma once
#include <string>
#include <iostream>

using namespace std;
/*
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ��str1�� into ��str2��.

Insert
Remove
Replace

All of the above operations are of equal cost.
*/

int my_min(int x, int y)
{ return (x <= y) ? x : y; }

int min(int x, int y, int z)
{ return my_min(x, my_min(y, z)); }

int editDistDP(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems
	int** dp = new int*[m + 1];
	for (int i = 0; i < m + 1; ++i)
		dp[i] = new int[n + 1] { 0 };

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// If first string is empty, only option is to
			// isnert all characters of second string
			if (i == 0)
				dp[i][j] = j;  // Min. operations = j

							   // If second string is empty, only option is to
							   // remove all characters of second string
			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

							  // If last characters are same, ignore last char
							  // and recur for remaining string
			else if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// If last character are different, consider all
			// possibilities and find minimum
			else {
				dp[i][j] = 1 + min(dp[i][j - 1],  // Insert
					dp[i - 1][j],  // Remove
					dp[i - 1][j - 1]); // Replace
			}
		}
	}


	return dp[m][n];
}