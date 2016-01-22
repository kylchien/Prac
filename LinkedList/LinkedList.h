#pragma once
#include <iostream>
using std::cout;
using std::endl;


struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
	~Node() {}
};

struct List 
{
	List(int v)
	{
		head = new Node(v);
	}

	List(Node* n):head(n) {}

	~List()
	{
		Node* cursor = head;
		while (cursor) 
		{
			Node* n = cursor;
			cursor = cursor->next;
			delete n;
		}
	}

	List& append(int v)
	{
		Node* n = new Node(v);
		Node* cursor = head;
		while (cursor->next) cursor = cursor->next;
		cursor->next = n;
		return *this;
	}

	void reverse()
	{
		Node* tail = head;
		while (tail->next) {
			Node* newHead = tail->next;
			Node* newNext = newHead->next;
			tail->next = newNext;
			newHead->next = head;
			head = newHead;
		}
	}

	void print()
	{
		Node* cursor = head;
		while (cursor) {
			if (cursor != head)
				cout << "->";
			cout << cursor->val;
			cursor = cursor->next;
		}
		cout << endl;
	}

	Node* head;
};