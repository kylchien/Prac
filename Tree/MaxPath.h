#pragma once
#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
For this problem, a path is defined as any sequence of nodes from 
some starting node to any node in the tree along the parent-child connections. 
The path does not need to go through the root.

For example:
Given the below binary tree,

  1
 / \
2   3

Return 6.

Catch:

For each current node, there are only 3 possible sums:

      5
	/   \
   2    -3  
  / \   /  \
 4   8 10  11

 1. root itself only (both children paths contains negative sum)
 2. root plus one of the children paths
 3. root plus both children paths

 Note that, once we choose both children path, we cannot advance
 for above example, 4-2-8-5 is invalid, we can either choose 4-2-8 or 4-2-5-...
*/


int MAX(int a, int b) { return (a>b) ? a : b; }
int MAX(int a, int b, int c) { return MAX(MAX(a, b), c); }

int maxPath(BinaryTree* root, int& sol) 
{

	if (root == NULL) return 0;
	int l = maxPath(root->left, sol);
	int r = maxPath(root->right, sol);
	int v = root->data;

	// we return onePath, since when we computes 
	// individual node sum, we cannot "connect"
	// both children path (as it will be captured)
	// in masSum below
	int onePath = MAX(MAX(l, r) + v, v); 
	int maxSum = MAX(l + r + v, onePath, v);
	sol = MAX(sol, maxSum);
	return onePath;
}

int maxPathSum(BinaryTree* root) {
	int sol = INT_MIN;
	maxPath(root, sol);
	return sol;
}


/*
     1
   /   \
  2     -3
/   \  /  \
4   8 10  -8
            \
			50
*/

void testMaxPathSum()
{
	BinaryTree* l = new BinaryTree(2, 4, 8);
	BinaryTree* r = new BinaryTree(-3, 10, -8);
	r->right->right = new BinaryTree(50);
	BinaryTree* t = new BinaryTree(1,l,r);
	printPretty(t, 1, 0, cout);

	cout << maxPathSum(t) << endl;
}