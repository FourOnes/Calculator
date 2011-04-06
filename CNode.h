#ifndef NODE_H
#define NODE_H

#include "CScanner.h"
#include "CTree.h"

class Node
{
friend class Tree;
public:
	Node();
	virtual ~Node();

	virtual bool IsOperation()=0;
	virtual void PrintData()=0;
	virtual double GetData()=0;
private:
	Node *left;
	Node *right;
};

class OpNode:public Node
{
public:
	OpNode(char);

	virtual bool IsOperation();
	virtual void PrintData();
	virtual double GetData();
private:
	char op;
};

class NumNode:public Node
{
public:
	explicit NumNode(double);

	virtual bool IsOperation();
	virtual void PrintData();
	virtual double GetData();
private:
	double number;
};
#endif