#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
using std::string;

#include "CScanner.h"
#include "CTree.h"

class Calculator
{
public:
	Calculator();
	Calculator(string);

	void SetExpression(string);
	string GetExpression();

	double Calculate();
private:
	string expression;
};
#endif