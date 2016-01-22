#include <iostream>
#include "LinkedList.h"
#include "RemoveDuplicate.h"
#include "Delete.h"
#include "NthToLast.h"
#include "Circle.h"
#include "AddTwoNumber.h"
#include "MergeTwoSortedList.h"
#include "MergeKSortedList.h"

using namespace std;

int main()
{
	/*
	List list(1);
	list.append(1).append(2).append(3).append(3).append(4).append(5).append(5);
	list.print();

	removeDuplicate(list);
	list.print();
	*/
	/*
	nth_to_last(list, 3);
	nth_to_last_recursive(list, 3);

	nth_to_last(list, 1);
	nth_to_last_recursive(list, 1);

	nth_to_last(list, 5);
	nth_to_last_recursive(list, 5);
	*/
	/*
	Node* node5 = list.head->next->next->next->next;
	list.head->next->next->next->next->next = node5;
	
	circle(list);
	*/

	//testAddTwoNumbers();
	//testMerge2SortedList();
	testMergeKSortedList();

	getchar();
	return 0;
}

