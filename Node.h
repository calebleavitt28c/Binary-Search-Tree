#ifndef __NODE__
#define __NODE__
#include "Observer.h"

class Node
{
public:
	Node(int data = 0, Node * leftChild = nullptr, Node * rightChild = nullptr);
	~Node() = default;
	bool IsLeaf();
	void UpdateHeight();

	int data;
	int height = 0;
	Node* leftChild;
	Node* rightChild;

private:
	Observer neededForUnitTest; //do not remove


};
#endif