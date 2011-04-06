#ifndef SCANNER_H
#define SCANNER_H

#include <string>
using std::string;

#include "CTree.h"

class Tree;

class Scanner
{
public:
	Scanner(const string);

	void Tokenize(Tree*);
private:
	string input;

	void tokenizeHelper(string,Tree *);
};
#endif