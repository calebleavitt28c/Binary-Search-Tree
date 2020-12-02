#ifndef __BINARRYSEARCHTREE__
#define __BINARYSEARCHTREE__
#include <string>
#include "Node.h"

class BinarySearchTree
{
public:
	BinarySearchTree(); //done
	~BinarySearchTree();;
	Node* DestructorHelper(Node* cursor);

	void Insert(int data); //done
	Node* Search(int data); //done
	void Remove(int data);
	void InorderTraversal(); //done
	void Print(); //done
	int Size();  //done 
	Node* Rotate();

	Node* root;
	Node* tmpNode = nullptr;
	int sizeofTree = 0;

private:
	Node* InsertHelper(Node* cursor, int data); //done
	Node* SearchHelper(Node* cursor, int data);	//done
	Node* RemoveHelper(Node* cursor, int data);
	void InorderHelper(Node* cursor);			//done
	void PrintHelper(std::string& offset, Node* cursor); //done
	int SizeHelper(Node* cursor);

};
#endif
