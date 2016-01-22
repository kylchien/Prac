#pragma once
#include "BinaryTree.h"
/*
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is de!ned to be a tree such that no two leaf nodes di$er in distance
from the root by more than one
*/


int my_max(int a, int b) 
{ return (a >= b) ? a : b; }

int my_min(int a, int b)
{ return (a < b) ? a : b; }


int max_height(BinaryTree* bt)
{
	if (bt == nullptr) { return 0;}
	return 1 + my_max(max_height(bt->left), max_height(bt->right));
}

int min_height(BinaryTree* bt)
{
	if (bt == nullptr) {return 0;}
	return 1 + my_min(min_height(bt->left), min_height(bt->right));
}

bool isBalanced(BinaryTree* bt)
{
	if (bt == nullptr) {
		return false;
	}
	return (max_height(bt) - min_height(bt)) <= 1;
}

