#include <iostream>
#include "BinarySearchTree.h"
#include "RecursionCounter.h"
#include "Node.h"
using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	Node* cursor = root;
	DestructorHelper(cursor);
}

Node* BinarySearchTree::DestructorHelper(Node* cursor)
{
	if (cursor == nullptr)
	{
		return nullptr;
	}

	if (cursor->IsLeaf())
	{
		delete cursor;
		return nullptr;
	}
	else
	{
		cursor->leftChild = DestructorHelper(cursor->leftChild);
		cursor->rightChild = DestructorHelper(cursor->rightChild);
		delete cursor;
		return nullptr;
	}
}


void BinarySearchTree::Insert(int data)
{
	root = InsertHelper(root, data);
}

Node* BinarySearchTree::InsertHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;	
	
	//base case
	if (cursor == nullptr)
		return new Node(data);

	//recursive cases
	if (data < cursor->data)
		cursor->leftChild = InsertHelper(cursor->leftChild, data);
	
	else
		cursor->rightChild = InsertHelper(cursor->rightChild, data);
	
	cursor->UpdateHeight();
	return cursor;
}


Node* BinarySearchTree::Search(int data)
{
	Node* cursor = root;
	cursor = SearchHelper(cursor, data);
	return cursor;
}

Node* BinarySearchTree::SearchHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;

	//base case
	if (cursor == nullptr)
	{
		tmpNode = cursor;
		return tmpNode;
	}

	else
	{
		if (cursor->data == data)
		{
			tmpNode = cursor;
			return tmpNode;
		}
		else if (data < cursor->data)
		{
			SearchHelper(cursor->leftChild, data);
		}
		else
		{
			SearchHelper(cursor->rightChild, data);
		}
	}

	return tmpNode;
}


void BinarySearchTree::Remove(int data)
{
	Node* cursor = root;
	root = RemoveHelper(cursor, data);
	return;
}

Node* BinarySearchTree::RemoveHelper(Node* cursor, int data)
{
	RecursionCounter neededForUnitTest;

	if (cursor == nullptr)
	{
		return cursor;
	}

	if (cursor->data == data)
	{
		if (cursor->IsLeaf())	//is this node a leaf if yes than we just remove it and update height make the parents child point to nullptr
		{
			delete cursor;
			cursor = nullptr;
			return cursor;
		}

		else  
		{
			if (cursor->leftChild != nullptr and cursor->rightChild != nullptr) //if it has two children make this nodes parent point to the successor node
			{
				Node* successor = cursor->rightChild;
				while (successor->leftChild != nullptr)
				{
					successor = successor->leftChild;
				}

				cursor->data = successor->data;

				cursor->rightChild = RemoveHelper(cursor->rightChild, successor->data);
				return cursor;
			}

			else
			{
				if (cursor->leftChild != nullptr)
				{
					Node* tmp = cursor->leftChild;
					delete cursor;
					cursor = nullptr;
					return tmp;
				}
				if (cursor->rightChild != nullptr)
				{
					Node* tmp = cursor->rightChild;
					delete cursor;
					cursor = nullptr;
					return tmp;
				}
			}
		}
	}

	else
	{
		if (data < cursor->data)
			cursor->leftChild = RemoveHelper(cursor->leftChild, data);

		else
			cursor->rightChild = RemoveHelper(cursor->rightChild, data);
	}

	cursor->UpdateHeight();
	return cursor;
}

// for inversetracersal its similar to print
void BinarySearchTree::InorderTraversal()
{
	Node* cursor = root;
	InorderHelper(cursor);
	cout << endl;
}

void BinarySearchTree::InorderHelper(Node* cursor)
{
	RecursionCounter neededForUnitTest;

	//base case
	if (cursor == nullptr)
		return;
	InorderHelper(cursor->leftChild);
	cout << cursor->data << ", ";
	InorderHelper(cursor->rightChild);
}
	

// when printing the height of each node don't use recursion just take it from the node
void BinarySearchTree::Print()
{
	std::string offset = "";
	Node* cursor = root;
	PrintHelper(offset, cursor);
}


void BinarySearchTree::PrintHelper(std::string& offset, Node* cursor)
{
	RecursionCounter neededForUnitTest;

	//base case
	if (cursor == nullptr)
	{
		cout << offset << "[Empty]" << endl;
		return;
	}

	//print node
	if (cursor != nullptr)
	{
		if (cursor->IsLeaf())
		{
			cout << offset << cursor->data << " (" << cursor->height << ")" << " " << "[leaf]" << endl;
			return;
		}
		else
		{
			cout << offset << cursor->data << " (" << cursor->height << ")" << " " << endl;
		}

		string tmp = offset + "   ";
		//check leftChild
			PrintHelper(tmp, cursor->leftChild);
		//check rightChild
			PrintHelper(tmp, cursor->rightChild);
	}

}

int BinarySearchTree::Size()
{
	sizeofTree = 0;
	Node* cursor = root;
	return SizeHelper(cursor);
}

int BinarySearchTree::SizeHelper(Node* cursor)
{
	RecursionCounter neededForUnitTest;			
	
	//base case
	if (cursor == nullptr)
	{
		return sizeofTree;
	}
	SizeHelper(cursor->leftChild);
	sizeofTree++;
	SizeHelper(cursor->rightChild);
	
	return sizeofTree;
}



