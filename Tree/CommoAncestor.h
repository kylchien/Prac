#pragma once
#include "BinaryTree.h"

bool isSubTree(BinaryTree* root, BinaryTree* target)
{
	if (root == nullptr) return false;

	if (root == target) return true;

	return isSubTree(root->left, target) || isSubTree(root->right, target);
}

// top-down - will visist the same node several times
// will be slow in large tree
BinaryTree* commonAncestor(BinaryTree* root, BinaryTree* p, BinaryTree* q)
{
	if (isSubTree(root->left, p) && isSubTree(root->left, q))
		return commonAncestor(root->left, p, q);
	else if (isSubTree(root->right, p) && isSubTree(root->right, q))
		return commonAncestor(root->right, p, q);
	else if (isSubTree(root, p) && isSubTree(root, q))
		return root;
	else
		return nullptr;
}


/*
A Bottom-up Approach (Worst case O(n) ):
Using a bottom-up approach, we can improve over the top-down approach by avoiding traversing the same nodes over and over again.

We traverse from the bottom, and once we reach a node which matches one of the two nodes, 
we pass it up to its parent. The parent would then test its left and right subtree if each contain one of the two nodes. 
If yes, then the parent must be the LCA and we pass its parent up to the root. If not, we pass the lower node which 
contains either one of the two nodes (if the left or right subtree contains either p or q), or 
NULL (if both the left and right subtree does not contain either p or q) up.

Sounds complicated? Surprisingly the code appears to be much simpler than the top-down one.
*/
/*
TreeNode* commonAncestor(BinaryTree* root, BinaryTree* p, BinaryTree* q) 
{
	if (!root) return nullptr;
	if (root == p || root == q) return root;
	BinaryTree *L = lowestCommonAncestor(root->left, p, q);
	BinaryTree *R = lowestCommonAncestor(root->right, p, q);
	if (L && R) return root;  // if p and q are on both sides
	return L ? L : R;
}
*/