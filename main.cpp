#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

#include <string>
using std::string;

#include "CCalculator.h"

int main(int argc, char *argv[])
{
   /*if (argc < 2)
   { 
      cerr << "You must specify calculating expression!!!"
      <<"\nBe attentive, please!!!"<<endl;
      system("pause"); 
      exit(1); 
   }*/

   ///string expression(argv[1]);
   ///string expression; 
   ///Calculator *calc=new Calculator("2+5*3");

   ///cout<<"Enter an expression to calculate: "<<endl;
   ///cin>>expression;

   Calculator *calc=new Calculator;
   calc->SetExpression("2.5*2,5+0.25*3-6/2");

   cout<<calc->GetExpression()<<" = ";
   cout<<calc->Calculate()<<endl;

   delete calc;

   system("pause");
   return 0;
}
