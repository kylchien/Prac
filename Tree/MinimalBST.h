#pragma once
#include "BinaryTree.h"

/*
Given a sorted (increasing order) array, write an algorithm 
to create a binary tree with minimal height
*/
BinaryTree* addToTree(int* array, int start, int end)
{
	if (start > end) return nullptr;

	int mid = start + (end - start) / 2;
	BinaryTree* bt = new BinaryTree(array[mid]);
	BinaryTree* lt = addToTree(array, start, mid - 1);
	BinaryTree* rt = addToTree(array, mid + 1, end);
	bt->left = lt;
	bt->right = rt;
	return bt;
}


BinaryTree* createMinimalBST(int* array, int n) {
	return addToTree(array, 0, n - 1);
}

