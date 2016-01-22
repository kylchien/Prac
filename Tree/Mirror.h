#pragma once
#include "BinaryTree.h"
#include <queue>
using namespace std;

void mirror(BinaryTree* tree)
{
	if (tree == nullptr) return;
	mirror(tree->left);
	mirror(tree->right);
	BinaryTree* tmp = tree->left;
	tree->left = tree->right;
	tree->right = tmp;
}


//nonrecursive
void mirror2(BinaryTree* tree)
{
	queue<BinaryTree*> q;
	q.push(tree);

	while (!q.empty())
	{
		BinaryTree* t = q.front();
		q.pop();

		if (t->left == nullptr && t->right == nullptr)
			continue;
		else if (t->left != nullptr && t->right != nullptr) {
			BinaryTree* tmp = t->left;
			t->left = t->right;
			t->right = tmp;
			q.push(t->left);
			q.push(t->right);
		}
		else if (t->left != nullptr && t->right == nullptr) {
			t->right = t->left;
			t->left = nullptr;
			q.push(t->right);
		}
		else {
			t->left = t->right;
			t->right = nullptr;
			q.push(t->left);
		}
	}
}