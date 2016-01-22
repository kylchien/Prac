#pragma once
#include "BinaryTree.h"
#include <sstream>
#include <iostream>

using namespace std;


bool isSubstring(const char* str, const char* sub)
{
	if (!*str || !*sub) return false;
	while (*str) {
		const char* copysub = sub;
		const char* copystr = str;
		bool match = true;
		while (*copysub) {
			if (*copysub != *copystr) {
				match = false;
				break;
			}
			copysub++;
			copystr++;
		}
		if (match) return true;
		str++;
	}
	return false;
}

bool isSubString(string& str, string& sub)
{
	if (str.compare("") == 0 || sub.compare("") == 0) return false;
	for (int i = 0; i < str.size(); ++i) {
		bool match = true;
		int x = i;
		for (int j = 0; j < sub.size(); ++j) {
			if (str[x] != sub[j]) {
				match = false;
				break;
			}
			x++;
		}
		if (match) return true;
	}
	return false;
}

void preorder(BinaryTree* t, ostringstream& o)
{
	if (t == nullptr) return;
	o << t->data;
	preorder(t->left, o);
	preorder(t->right, o);
}

void inorder(BinaryTree* t, ostringstream& o)
{
	if (t == nullptr) return;
	inorder(t->left, o);
	o << t->data;
	inorder(t->right, o);
}

/*
main idea:

compare preorder sequence of the two and inorder sequence of the two
if small tree's string is substring of large tree's string
it is indeed a subtree of large tree

Though this is O(n) where n is large tree's size 
if big tree is very very big, this method might not be viable
eg: exceed memory limit due to the super long string we create
*/
bool isSubtree(BinaryTree* big, BinaryTree* small)
{
	if (big == nullptr) return false;
	if (small == nullptr) return true;

	ostringstream oss1;
	preorder(big, oss1);
	ostringstream oss2;
	preorder(small, oss2);

	if (!isSubString(oss1.str(), oss2.str())) return false;

	ostringstream oss3;
	inorder(big, oss3);
	ostringstream oss4;
	inorder(small, oss4);

	if (!isSubString(oss3.str(), oss4.str())) return false;

	return true;
}


bool areIdentical(BinaryTree* root1, BinaryTree* root2)
{
	/* base cases */
	if (root1 == nullptr && root2 == nullptr)
		return true;

	if (root1 == nullptr || root2 == nullptr)
		return false;

	/* Check if the data of both roots is same and data of left and right
	subtrees are also same */
	return (root1->data == root2->data   &&
		areIdentical(root1->left, root2->left) &&
		areIdentical(root1->right, root2->right));
}

//recursive
//no extra memory storage
//expensive: Worst case runtime is at
//most O(n * m), where n and m are the sizes of trees T1 and T2, respectively.
bool isSubtree2(BinaryTree* big, BinaryTree* small)
{
	if (big == nullptr) return false;
	if (small == nullptr) return true;

	if (areIdentical(big, small)) return true;

	return (isSubtree2(big->left, small)) || (isSubtree2(big->right,small));
}
