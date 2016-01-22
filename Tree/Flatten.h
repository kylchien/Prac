#pragma once
#include "BinaryTree.h"
#include <iostream>

using namespace std;

/*
given 

   1
  / \
 2   5
/ \   \
3  4   6

return 

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

catch: If you notice carefully in the flattened tree, 
each node's right child points to the next node of a pre-order traversal.

*/

BinaryTree* helper(BinaryTree* t)
{
	if (t == NULL) return NULL;
	BinaryTree* l = helper(t->left);
	BinaryTree* r = helper(t->right);
	t->left = NULL;
	t->right = l;
	BinaryTree* point = t;
	while (point->right) point = point->right;
	point->right = r;
	return t;
}

void flatten(BinaryTree* root) {
	root = helper(root);
}


void testFlatten()
{
	BinaryTree* bt = new BinaryTree(1);
	BinaryTree* bt1 = new BinaryTree(2, 3, 4);
	bt->left = bt1;
	bt->right = new BinaryTree(5);
	bt->right->right = new BinaryTree(6);

	printPretty(bt, 1, 0, cout);

	flatten(bt);

	cout << endl;

	BinaryTree* pointer = bt;
	while (pointer) {
		cout << pointer->data << " ";
		pointer = pointer->right;
	}
	cout << endl;
	
	deleteTree(bt);
	
}