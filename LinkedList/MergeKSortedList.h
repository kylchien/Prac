#pragma once
#include "LinkedList.h"
#include <vector>
#include <iostream>
using namespace std;
/*
https://leetcode.com/problems/merge-k-sorted-lists/
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

Node* merge2Lists(Node *h1, Node *h2);

//CLEVER WAY to MERGE pairs of lists until we have a final one
//this sol can pass time test for large amounts of small lists
Node* mergeKLists(vector<Node *>& lists) {
	if (lists.empty()) return NULL;
	int end = lists.size() - 1;
	while (end>0) {
		int begin = 0;
		while (begin<end) {
			lists[begin] = merge2Lists(lists[begin], lists[end]);
			begin++;
			end--;
		}
	}
	return lists[0];
}

Node* merge2Lists(Node *h1, Node *h2) {
	Node *dummy = new Node(0), *tail = dummy;
	while (h1 && h2) {
		if (h1->val <= h2->val) {
			tail->next = h1;
			h1 = h1->next;
		}
		else {
			tail->next = h2;
			h2 = h2->next;
		}
		tail = tail->next;
	}
	tail->next = h1 ? h1 : h2;
	return dummy->next;
}


void testMergeKSortedList()
{
	List l(0);
	l.append(2).append(4).append(6).append(8);
	List r(1);
	r.append(3).append(5);
	List u(-3);
	u.append(-2).append(-1).append(7).append(9).append(10);
	vector<Node*> v;
	v.push_back(l.head); v.push_back(r.head); v.push_back(u.head);

	Node* n = mergeKLists(v);
	List sol(n);
	sol.print();

	//resource will be cleaned up while sol is popped out from stack
	l.head = nullptr;
	r.head = nullptr;
	u.head = nullptr;
}