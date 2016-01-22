#pragma once
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space res1pectively.

For example,
There exist two distinct solutions to the 4 - queens puzzle :

[
	[".Q..",  // Solution 1
	"...Q",
	"Q...",
	"..Q."],

	["..Q.",  // Solution 2
	"Q...",
	"...Q",
	".Q.."]
]


1) Start in the leftmost column
2) If all queens are placed
return true
3) Try all rows in the current column.  Do following for every tried row.
a) If the queen can be placed safely in this row then mark this [row,
column] as part of the solution and recursively check if placing
queen here leads to a solution.
b) If placing queen in [row, column] leads to a solution then return
true.
c) If placing queen doesn't lead to a solution then umark this [row,
column] (Backtrack) and go to step (a) to try other rows.
3) If all rows have been tried and nothing worked, return false to trigger
backtracking.

*/

inline int ABS(int i) { return (i < 0) ? -i : i; }

bool isValid(int i, int j, vector<pair<int, int>>& queens)
{
	for (auto p : queens) {
		if (p.first == i) return false;   //row
		if (p.second == j) return false;  //col
		if (ABS(i - p.first) == ABS(j - p.second)) return false; //diagonal
	}
	return true;
}

void backtrack(int n, int col, vector<pair<int, int>>& queens)
{
	if (col >= n) {
		for (auto p : queens) {
			cout << "(" << p.first << ", " << p.second << ")\n";
		}
		cout << endl << endl;
	}
	for (int i = 0; i < n; ++i) {
		if (isValid(i, col, queens)) {
			queens.push_back(pair<int, int>(i, col));
			backtrack(n, col + 1, queens);
			queens.pop_back();
		}
	}
}
/*
vector<vector<string>> solveNQueens(int n) 
{
	vector<vector<string>> output;
	vector<pair<int,int>> queens;
	return output;
}*/

vector<vector<string>> res1;

void printres1(vector<int> A, int n) {
	vector<string> r;
	for (int i = 0;i<n;i++) {
		string str(n, '.');
		str[A[i]] = 'Q';
		r.push_back(str);
	}
	res1.push_back(r);
}


bool isValid(vector<int> A, int r) {
	for (int i = 0;i<r;i++) {
		if ((A[i] == A[r]) || (abs(A[i] - A[r]) == (r - i))) {
			return false;
		}
	}
	return true;
}

void nqueens(vector<int> A, int cur, int n) {
	if (cur == n) { printres1(A, n); }
	else {
		for (int i = 0;i<n;i++) {
			A[cur] = i;
			if (isValid(A, cur)) {
				nqueens(A, cur + 1, n);
			}
		}
	}
}
//A[i]=j means i_th row, j_th col a queen is placed
vector<vector<string>> solveNQueens(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	res1.clear();
	vector<int> A(n, -1);
	nqueens(A, 0, n);
	return res1;
}

void testNQueens()
{
	
	vector<pair<int, int>> queens;
	backtrack(4, 0, queens);
	//for (auto p : queens) {
	//	cout << "(" << p.first << ", " << p.second << ")\n";
	//}

	/*
	vector<vector<string> > v = solveNQueens(4);
	for (auto vec : v) {
		for (string& s : vec) {
			cout << s.c_str() << endl;
		}
		cout <<  endl << endl;
	}*/
}