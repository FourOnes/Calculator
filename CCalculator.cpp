#include <iostream>
using std::cout;
using std::endl;

#include "CCalculator.h"

Calculator::Calculator():expression("") {}

Calculator::Calculator(string exp=""):expression(exp) {}

void Calculator::SetExpression(string exp)
{
   expression=exp;
}

string Calculator::GetExpression()
{
   return expression;
}

double Calculator::Calculate()
{
	if(!expression.empty())
	{
	   Scanner scanner(expression);
	   Tree tree;

	   scanner.Tokenize(&tree);
	   return tree.Calculate();
	}
	else 
	{
	   cout<<"Math string is empty! Specify it!"<<endl;
	   return 0;
	}
}