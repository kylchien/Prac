#pragma once
#include "LinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

void nth_to_last(List& list, int n)
{
	if (n < 1 || list.head == nullptr) return;

	Node* nth = list.head;
	Node* scan = list.head;

	for (int i = 0; i < n; ++i) {
		//n is > list length
		if (scan == nullptr) return;
		scan = scan->next;
	}

	while (scan) {
		scan = scan->next;
		nth = nth->next;
	}

	cout << "nth to last:" << nth->val << endl;
}





// main function
static void find(Node* node, int n, int& c)
{
	if (node == nullptr) return;

	find(node->next, n, c);
	
	if (++c == n) {
		cout << "nth to last(recursive):" << node->val << endl;
	}
}

static void nth_to_last_recursive(List& list, int n)
{
	static int c = 0;
	find(list.head, n, c);
	c = 0;
}

