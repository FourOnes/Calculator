#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include "CTree.h"
#include "CNode.h"

Tree::Tree():root(0) {}

Tree::~Tree()
{
	if(root)
		delete root;
}

void Tree::Insert(Node *value)
{
	bool state=false;
	insertHelper(&root,value,state);
}

void Tree::insertHelper(Node **ptr,Node *value,bool &state)
{
	if(*ptr==0)
	{
		*ptr=value;
		state=true;
	}
	else
	{
		if( !((*ptr)->left) || (*ptr)->left->IsOperation())
		{
			insertHelper(&((*ptr)->left),value,state);
			if(!state)
				insertHelper(&((*ptr)->right),value,state);
		}
		else if( !((*ptr)->right) || (*ptr)->right->IsOperation())
			insertHelper(&((*ptr)->right),value,state);
	}
}

void Tree::Inorder()
{
	inorderHelper(root);  
}

void Tree::inorderHelper(Node *child)
{
	if(child)
	{
		inorderHelper(child->left);
		child->PrintData();
		inorderHelper(child->right);
	}
}

double Tree::Calculate()
{
   try
   {
   calculateHelper(&root);
   }
   catch(runtime_error &ex)
   {
      cout<<"\n\nException occured : "<<ex.what()<<endl; 
	  system("pause");
	  exit(1);
   }
   return dynamic_cast<NumNode *>(root)->GetData();
}

void Tree::calculateHelper(Node **parent)
{
	if((*parent)->IsOperation())
	{
		if( !((*parent)->left->IsOperation()) && !((*parent)->right->IsOperation()))
		{
			double operand1=(*parent)->left->GetData();
			double operand2=(*parent)->right->GetData();
			double result=performOperation(*parent,operand1,operand2);
			
			delete *parent;
			*parent=new NumNode(result);
		}
		else if( (*parent)->left->IsOperation() )
		{
			calculateHelper( &((*parent)->left) );
			calculateHelper( &(*parent) );
		}
		else if( (*parent)->right->IsOperation() )
		{
			calculateHelper( &((*parent)->right) );
			calculateHelper( &(*parent) );
		}
	}
}

double Tree::performOperation(Node *operation,double operand1,double operand2)
{
    double result=0;
	char op=operation->GetData();

	if( op == '+') 
       result=operand1+operand2;
    else if( op == '-') 
       result=operand1-operand2; 
    else if( op == '*') 
       result=operand1*operand2;
    else if( op == '/')
	{	
		if(operand2!=0)
		   result=operand1/operand2;
	    else
           throw runtime_error("attempted to divide by zero");
	}
	return result;
}