#pragma once
#include "BinaryTree.h"
#include "Balance.h" 
#include <iostream>
#include <queue>
using namespace std;

void preorder(BinaryTree* tree)
{
	if (tree == nullptr) return;
	cout << tree->data << " ";
	preorder(tree->left);
	preorder(tree->right);
}


void inorder(BinaryTree* tree)
{
	if (tree == nullptr) return;
	inorder(tree->left);
	cout << tree->data << " ";
	inorder(tree->right);
}

void postorder(BinaryTree* tree)
{
	if (tree == nullptr) return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->data << " ";
}


void levelorder(BinaryTree* tree)
{
	if (tree == nullptr) return;

	queue<BinaryTree*> q;
	BinaryTree* cursor = tree;

	while (cursor) {
		cout << cursor->data << " ";
		if (cursor->left)
			q.push(cursor->left);
		if (cursor->right)
			q.push(cursor->right);
		
		if (q.empty())
			break;
		cursor = q.front();
		q.pop();
	}
	
}


void printGivenLevel(BinaryTree* t, int level)
{
	if (t == nullptr) return;
	if (level == 1) cout << t->data << " ";
	else if (level > 1) {
		printGivenLevel(t->left, level-1);
		printGivenLevel(t->right, level-1);
	}
}
//recursive
void levelorder2(BinaryTree* tree)
{
	int height = max_height(tree);
	for (int i = 1; i <= height; ++i)
		printGivenLevel(tree, i);
}

