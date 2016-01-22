#pragma once
#include "LinkedList.h"
#include <iostream>

using namespace std;

/*
If we move two pointers, one with speed 1 and another with speed 2, they will end up
meeting if the linked list has a loop. Why? Think about two cars driving on a track¡Xthe
faster car will always pass the slower one!

The tricky part here is finding the start of the loop. Imagine, as an analogy, two people
racing around a track, one running twice as fast as the other. If they start of at the same
place, when will they next meet? They will next meet at the start of the next lap.

Now, let¡¦s suppose Fast Runner had a head start of k meters on an n step lap. When will
they next meet? They will meet k meters before the start of the next lap. (Why? Fast Runner
would have made k + 2(n - k) steps, including its head start, and Slow Runner would have
made n - k steps. Both will be k steps before the start of the loop.)

Now, going back to the problem, when Fast Runner (n2) and Slow Runner (n1) are moving
around our circular linked list, n2 will have a head start on the loop when n1 enters.
Specifically, it will have a head start of k, where k is the number of nodes before
the loop. Since n2 has a head start of k nodes, n1 and n2 will meet k nodes before the
start of the loop. So, we now know the following:

1. Head is k nodes from LoopStart (by de!nition).
2. MeetingPoint for n1 and n2 is k nodes from LoopStart (as shown above).

Thus, if we move n1 back to Head and keep n2 at MeetingPoint, and move them both at the
same pace, they will meet at LoopStart.
*/


void circle(List& list)
{
	Node* slow = list.head;
	Node* fast = list.head;

	do {
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
		else {
			cout << "no circle" << endl;
			return;
		}
			
	} while (fast && slow!=fast);

	slow = list.head;

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	cout << "circle starts at " << slow->val << endl;
}

