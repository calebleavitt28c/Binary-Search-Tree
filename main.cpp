#include <iostream>
#include "BinarySearchTree.h"
#include "Observer.h"
#include "RecursionCounter.h"

using namespace std;

// needed for Unit Testing. DO NOT REMOVE
int Observer::numConstructions = 0;
int Observer::numDestructions = 0;
int RecursionCounter::currentDepth = 0;
int RecursionCounter::maxDepth = 0;

int main()
{
	int data[] = { 21,26,30,9,4,14,28,18,15,10,2,3,7 };

	BinarySearchTree bst;

	for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		bst.Insert(data[i]);
	}

	bst.InorderTraversal();
	bst.Print();
	cout << endl << endl;

	bst.Remove(21); 
	bst.Remove(9);
	bst.Remove(4);
	bst.Remove(18);
	bst.Remove(15);
	bst.Remove(7);
	cout << endl;

	bst.Print();

	cout << endl << endl;
	bst.InorderTraversal();	 
}