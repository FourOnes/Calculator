#include <iostream>
using std::cout;

#include "CNode.h"

Node::Node():left(0),right(0) {}

Node::~Node()
{
	if(left)
		delete left;
	if(right)
		delete right;
}

OpNode::OpNode(char s):op(s) {}

bool OpNode::IsOperation()
{
	return true;
}

void OpNode::PrintData()
{
	cout<<op;
}

double OpNode::GetData()
{
   return op;
}

NumNode::NumNode(double n):number(n) {}

bool NumNode::IsOperation()
{
	return false;
}

void NumNode::PrintData()
{
	cout<<number;
}

double NumNode::GetData()
{
   return number;
}

