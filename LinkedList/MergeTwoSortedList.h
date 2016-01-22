#pragma once
#include "LinkedList.h"
#include <iostream>
using namespace std;

/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
*/

Node* mergeTwoSortedList(Node* n1, Node* n2)
{
	Node* sol = new Node(0);
	Node* p = sol;
	while (1){
		if (n1 == nullptr) {
			p->next = n2;
			break;
		}
		if (n2 == nullptr) {
			p->next = n1;
			break;
		}
		if (n1->val < n2->val) {
			p->next = n1;
			n1 = n1->next;
		}
		else {
			p->next = n2;
			n2 = n2->next;
		}
		p = p->next;
	}
	return sol->next;
}



void testMerge2SortedList()
{
	List l(0); 
	l.append(2).append(4).append(6).append(8);
	List r(1);
	r.append(3).append(5);

	Node* n = mergeTwoSortedList(l.head, r.head);
	List sol(n);
	sol.print();

	//resource will be cleaned up while sol is popped out from stack
	l.head = nullptr; 
	r.head = nullptr;
}