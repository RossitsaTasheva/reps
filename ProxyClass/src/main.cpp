// Fig. 10.27: main.cpp
// Hiding a class�s private data with a proxy class.
#include <iostream>
#include "Interface.h"
using namespace std;

int main()
{
   Interface i( 5 );
 
   cout << "Interface contains: " << i.getValue() 
      << " before setValue" << endl;

   i.setValue( 10 );

   cout << "Interface contains: " << i.getValue() 
      << " after setValue" << endl;
   return 0;
}
