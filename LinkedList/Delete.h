#pragma once
#include "LinkedList.h"
/*
Implement an algorithm to delete a node in the middle of a single linked list, 
given only access to that node.

EXAMPLE
Input : the node ¡¥c¡¦ from the linked list a->b->c->d->e
Result : nothing is returned, but the new linked list looks like a->b->d->e

The solution to this is to simply copy the data from the next node 
into this node and then delete the next node.

NOTE: This problem can not be solved if the node to be deleted is the last node
in the linked list. That¡¦s ok¡Xyour interviewer wants to see you point that out. You
could consider marking it as dummy in that case. 
This is an issue you should discuss with your interviewer.
*/

void deleteWithNoOtherAccess(Node* n)
{
	Node* victim = n->next;
	n->val = victim->val;
	n->next = victim->next;
	delete victim;
}

