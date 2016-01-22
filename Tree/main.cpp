#include "BinaryTree.h"
#include "Balance.h"
#include "MinimalBST.h"
#include "Traversal.h"
#include "Mirror.h"
#include "CommoAncestor.h"
#include "Subtree.h"
#include "Flatten.h"
#include "SortedListToTree.h"
#include "MaxPath.h"
using namespace std;


void example()
{
	BinaryTree *root = new BinaryTree(30);
	root->left = new BinaryTree(20);
	root->right = new BinaryTree(40);
	root->left->left = new BinaryTree(10);
	root->left->right = new BinaryTree(25);
	root->right->left = new BinaryTree(35);
	root->right->right = new BinaryTree(50);
	root->left->left->left = new BinaryTree(125);
	root->left->left->right = new BinaryTree(15);
	root->left->right->right = new BinaryTree(28);
	root->right->right->left = new BinaryTree(41);

	cout << "Tree pretty print with level=1 and indentSpace=0\n\n";
	// Output to console
	printPretty(root, 1, 0, cout);

	cout << "\n\nTree pretty print with level=5 and indentSpace=3,\noutput to file \"tree_pretty.txt\".\n\n";
	// Create a file and output to that file
	//ofstream fout("tree_pretty.txt");
	// Now print a tree that's more spread out to the file
	//printPretty(root, 5, 0, fout);
}


int main()
{
	//int array[7] = {0,1,2,3,4,5,6};
	//BinaryTree* t = createMinimalBST(array, 7);
	//printPretty(t, 1, 0 ,cout);
	//deleteTree(t);

	//testFlatten();
	
	//testSortedNodeListToTree();
	testMaxPathSum();
	
	getchar();
	return 0;
}