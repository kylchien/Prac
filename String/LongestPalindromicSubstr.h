#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/longest-palindromic-substring/
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

catch:
s[i][j] = s[i]==s[j] && s[i+1][j-1]

where i is the start index and j is end index and s[i][j] represents
whether substring s(i to j) is palindromic

example:

"bxbc"    => first fill len =1 => (0,0) (1,1) (2,2) (3,3), this is base case and always true 
          => then len =2 => (0,1) (1,2) (2,3) 
1 0 1 0   => then len =3 => (0,2) (1,3)
0 1 0 0   => then len =4 => (0,4)
0 0 1 0
0 0 0 1

so position (0,2) has the palindromic string with length 3

*/



string longestPalindrome(string s)
{
	int n = s.size();
	if (n <2) { return s; }
	if (n == 2) {
		if (s[0] == s[1]) return s;
		else return s.substr(0, 1);
	}

	bool table[1000][1000] = { false };

	int maxst = 0;
	int maxlen = 1;

	for (int i = 0; i < n; i++) {
		table[i][i] = true;
		maxst = i;
		maxlen = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true;
			maxst = i;
			maxlen = 2;
		}
	}

	for (int d = 2; d < n; ++d) {
		int i = 0, j = i + d;
		while (j < n) {
			if (s[i] == s[j] && table[i + 1][j - 1]) {
				table[i][j] = true;
				maxst = i;
				maxlen = d+1;
			}
			i++;j++;
		}
	}
	
	/*
	for (int i = 0;i < n; i++){
		for (int j = 0; j < n;j++)
			cout << table[i][j] << " ";
		cout << endl;
	}*/

	return s.substr(maxst, maxlen);
}


void testLongestPalindrome()
{
	string s = "xbxbcdefgfedcbxba";
	cout << longestPalindrome(s) << endl;

}


