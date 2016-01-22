#pragma once
#include "BinaryTree.h"
#include <iostream>

using namespace std;


/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Catch:
In the previous array to BST, we construct the BST in a top-down way. 
For the list data structure, to get the mid point every time is a waste of time. 
Hence construct the BST in a bottom-up way. 
However, the length of the list must be computed first.

Recursively
1. construct the left tree
2. construct the root node, list pointer +1.
3. construct the right node
*/

class ListNode
{
public:

	int val;
	ListNode* next;
	ListNode(int n) :val(n), next(nullptr) {}
	~ListNode() {}
	ListNode* append(int n) {
		this->next = new ListNode(n);
		return this->next;
	}
};

void deallocate(ListNode* node) {
	ListNode* copy = node;
	while (copy) {
		ListNode* tmp = copy;
		copy = copy->next;
		delete tmp;
	}
}

//pass the pointer as reference
//so the pointer will be updated in recursive call!!
BinaryTree* nodeToTree(ListNode*& list, int start, int end)
{
	if (start > end) return nullptr;

	int mid = start + (end - start) / 2;

	BinaryTree* l = nodeToTree(list, start, mid-1);
	BinaryTree* t = new BinaryTree(list->val);
	list = list->next;
	BinaryTree* r = nodeToTree(list, mid+1, end);
	t->left = l;
	t->right = r;
	return t;
}

BinaryTree* SortedListNodeToTree(ListNode* list)
{
	if (list == nullptr) return nullptr;
	ListNode* p = list;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	return nodeToTree(list,1,len);
}






void testSortedNodeListToTree()
{
	ListNode* node = new ListNode(1);
	node->append(2)->append(3)->append(4)
		->append(5)->append(6)->append(7)
		->append(8)->append(9)->append(10)
		->append(11)->append(12)->append(13)
		->append(14)->append(15);
	ListNode* copy = node;
	while (copy) {
		cout << copy->val << " ";
		copy = copy->next;
	}
	cout << endl;
	
	BinaryTree* t = SortedListNodeToTree(node);
	
	printPretty(t, 1, 0, cout);

	deallocate(node);
}

