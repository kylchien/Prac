#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
n = 3, k = 2 we have {1, 2}, {1, 3}, {2, 3}
*/

//s is the starting int we will add to base
//base is prefix
void combination(int n, int k, int s, vector<int> base, vector<vector<int>>& sol)
{
	//cout << "k=" << k << ", s=" << s << endl;

	if (k == 1) {
		base.push_back(s);
		sol.push_back(base);
		return;
	}
	
	base.push_back(s);
	for (int i = s+1; i <= n; ++i) {
		vector<int> copy;
		for (auto v : base)
			copy.push_back(v);
		combination(n, k-1, i, copy, sol);
	}
}


vector<vector<int>> combination(int n, int k)
{
	vector<vector<int>> sol;
	if (k > n || n < 1 || k < 1) return sol;

	if (k == n) {
		vector<int> v;
		for (int i = 1; i <= n;++i)
			v.push_back(i);
		sol.push_back(v);
	}
	else {
		vector<int> base;
		for (int i = 1; i <= n;++i)
			combination(n, k, i, base, sol);
	}
	return sol;
}



//DFS solution
vector<vector<int> > res;

void dfs(vector<int> &cand, int st, int ed, vector<int> &comb) 
{
	if (comb.size() == ed) {
		res.push_back(comb);
		return;
	}
	for (int i = st; i < cand.size();i++) {
		comb.push_back(cand[i]);
		dfs(cand, i + 1, ed, comb);
		comb.pop_back();
	}
}

vector<vector<int>> combination2(int n, int k)
{
	if ((k<1) || (n<1) || (k>n)) { return res; }
	vector <int> pivot;
	for (int i = 1; i <= n;i++) {
		pivot.push_back(i);
	}
	vector<int> lr;
	dfs(pivot, 0, k, lr);
	return res;
}






void testCombination()
{
	vector<vector<int>> sol;
	//combination(3, 1);
	//combination(3, 3);
	sol = combination2(5, 2);

	for (auto v : sol) {
		cout << "[";
		for (auto i : v) {
			cout << i << " ";
		}
		cout << "]\n";
	}
}