#pragma once
#include "LinkedList.h"
#include <iostream>
#include "../test.h"

using namespace std;

/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

The reverse order actually helps to solve this problem.
All we need is to have extra variable to store the carry value 
(if the sum is larger than 10) to next digit.

say, 
input (6), (4)
output 0->1
*/

//notice the sol is a reference of Node pointer
void helper(Node*& sol, Node* l1, Node* l2, int carry) {
	if (l1 == NULL && l2 == NULL) {
		if (carry)
			sol->next = new Node(1);
		return;
	}

	int sum = 0;
	int c = 0;

	if (l1 == NULL) {
		sum = l2->val + carry;
		l2 = l2->next;
	}
	else if (l2 == NULL) {
		sum = l1->val + carry;
		l1 = l1->next;
	}
	else {
		sum = l1->val + l2->val + carry;
		l1 = l1->next; l2 = l2->next;
	}

	sol->next = new Node(sum % 10);
	sol = sol->next;
	c = (sum >= 10) ? 1 : 0;
	helper(sol, l1, l2, c);
}


Node* addTwoNumbers(Node* l1, Node* l2) {
	int carry = 0;
	Node* sol = new Node(0);          //for simplicity the "real head" stores nothing
	Node* head = sol;
	helper(head, l1, l2, carry);
	return sol->next;

}

void testAddTwoNumbers()
{
	List l1(4);
	List l2(6);
	Node* n = addTwoNumbers(l1.head, l2.head);
	List sol(n);
	cout << "expect:0->1\nactual:";
	sol.print();
	cout << endl;

	//243 564
	List l3(2); l3.append(4).append(3);
	List l4(5); l4.append(6).append(4);
	Node* n1 = addTwoNumbers(l3.head, l4.head);
	List sol2(n1);
	cout << "expect:7->0->8\nactual:";
	sol2.print();
	cout << endl;
}