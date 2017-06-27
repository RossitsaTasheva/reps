//============================================================================
// Name        : ~Algorithm_rotate.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// rotate algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::rotate
#include <vector>       // std::vector

using namespace std;
void  write(vector<int> myvector){
	cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
				++it)
			cout << ' ' << *it;
		cout << '\n';

}

int main() {
	vector<int> v;

	// set some values:
	for (int i = 1; i < 10; ++i)
		v.push_back(i); // 1 2 3 4 5 6 7 8 9
	write(v);
	rotate(v.begin(), v.begin() + 3, v.end());
	// 4 5 6 7 8 9 1 2 3
	// print out content:
	write(v);
	return 0;
}
