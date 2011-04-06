#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cctype>
using std::isdigit;

#include <cstdlib>
using std::atof;

#include <stdexcept>
using std::runtime_error;

#include "CScanner.h"
#include "CNode.h"
#include "CTree.h"

Scanner::Scanner(const string expression): input(expression) {}

void Scanner::Tokenize(Tree *synTree)
{
	try
	{
       tokenizeHelper(input,synTree);
	}
	catch(runtime_error &ex)
	{
	   cout<<"\n\nException occured : "<<ex.what()<<endl; 
	   system("pause");
	   exit(1);
	}
}

void Scanner::tokenizeHelper(string source,Tree* synTree)
{
   const string op="+-*/";
   size_t pos=string::npos;
   string left;
   string right;

   for(string::const_iterator it=op.begin();it<op.end();++it)
   {
       pos=source.find_first_of(*it);
       
	   if(pos!=string::npos)
       {
		   synTree->Insert(new OpNode(*it));

	       left=source.substr(0,pos);
	       right=source.substr(pos+1,source.size()-1);

	       tokenizeHelper(left,synTree);       
	       tokenizeHelper(right,synTree);
		   break;
       }
   }
   
   if(pos==string::npos)
   {
	   string::iterator it;

	   for(it=source.begin();it<source.end();++it)
	   {   
		   if(*it=='.' || *it==',' || isdigit(*it))
		   {	
			   if(*it==',')
			   {
			      source.erase(it);
			      source.insert(it,1,'.');
			   }
		   }
		   else
		   {
			   throw runtime_error("unrecognized symbol");
		   }
	   }
	   
	   if(it==source.end())
	   {
		   synTree->Insert( new NumNode( atof( source.c_str() ) ) );
	   }
   }
}
