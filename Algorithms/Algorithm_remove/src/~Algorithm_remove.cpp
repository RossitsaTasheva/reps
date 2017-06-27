//============================================================================
// Name        : ~Algorithm_remove.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// remove algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove
using namespace std;
int main () {
  int arr[] = {10,20,30,30,20,10,10,20};      // 10 20 30 30 20 10 10 20

  // bounds of range:
  int* pbegin = arr;                          // ^
  int* pend = arr+sizeof(arr)/sizeof(int); // ^                       ^

  pend = remove (pbegin, pend, 20);         // 10 30 30 10 10 ?  ?  ?
                                                 // ^              ^
cout << "range contains:";
  for (int* p=pbegin; p!=pend; ++p)
    cout << ' ' << *p;
  cout << '\n';

  return 0;
}
