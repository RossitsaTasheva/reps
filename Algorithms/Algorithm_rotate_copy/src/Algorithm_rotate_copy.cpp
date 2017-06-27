//============================================================================
// Name        : ~Algorithm_rotate_copy.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// rotate_copy algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::rotate_copy
#include <vector>       // std::vector
using namespace std;
void  write(vector<int> myvector){
	cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
				++it)
			cout << ' ' << *it;
		cout << '\n';

}

int main () {
  int arr[] = {10,20,30,40,50,60,70};

vector<int> v (7);
write(v);
 rotate_copy(arr,arr+3,arr+7,v.begin());
write(v);

  return 0;
}
