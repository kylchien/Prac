#pragma once
#include "LinkedList.h"

//no extra space allows (otherwise we can use hash table to save known value)
void removeDuplicate(List& list)
{
	Node* pivot = list.head;
	while (pivot) {
		Node* prev = pivot;
		Node* scan = pivot->next;
		while (scan) {
			if (pivot->val == scan->val) {
				Node* tmp = scan;
				scan = scan->next;
				prev->next = scan;
				delete tmp;
			}

			//reach the end
			if (!scan) break;

			prev = scan;
			scan = scan->next;
		}
		pivot = pivot->next;
	}
}