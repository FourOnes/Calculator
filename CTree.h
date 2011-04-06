#ifndef TREE_H
#define TREE_H

#include "CNode.h"

class Node;

class Tree
{
public:
	Tree();
	~Tree();

	void Insert(Node *);
	void Inorder();	
	double Calculate();
private:
	Node *root;

	void insertHelper(Node**,Node*,bool &);
	void inorderHelper(Node *);
	void calculateHelper(Node **);
	double performOperation(Node *,double,double);
};
#endif