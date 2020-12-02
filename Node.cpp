#include "Node.h"

Node::Node(int data, Node* leftChild, Node* rightChild)
{
	this->data = data;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}

bool Node::IsLeaf()
{
	if (leftChild == nullptr and rightChild == nullptr)
		return true;
	else
		return false;
}

void Node::UpdateHeight()
{
	if (IsLeaf())
	{
		height = 0;
		return;
	}

	int left = 0;
	int right = 0;


		if (leftChild != nullptr)
		{
			left = leftChild->height;
		}
		else
			left = -1;

		if (rightChild != nullptr)
		{
			right = rightChild->height;
		}
		else
			right = -1;

		if (left < right)
		{
			height = right + 1;
			return;
		}
		else
		{
			height = left + 1;
			return;
		}
}
