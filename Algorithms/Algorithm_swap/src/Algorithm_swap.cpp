//============================================================================
// Name        : ~Algorithm_swap.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// swap algorithm example (C++98)
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector
using namespace std;

void write(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}

int main() {

	int x = 10, y = 20;                              // x:10 y:20
	swap(x, y);                              // x:20 y:10

	vector<int> v1(4, x), v2(6, y);       // foo:4x20 bar:6x10
	write(v1);
	write(v2);
	swap(v1, v2);                          // foo:6x10 bar:4x20
	cout << "\n~~~~~~~~~~~~~\n";
	write(v1);
	write(v2);
	cout << "\n-----------------------\n";
	vector<int> v3(5, 10);        // foo: 10 10 10 10 10
	vector<int> v4(5, 33);        // bar: 33 33 33 33 33
	write(v3);
	write(v4);
	swap_ranges(v3.begin() + 1, v3.end() - 1, v4.begin());
	cout << "\n~~~~~~~~~~~~~\n";
	write(v3);
	write(v4);

	return 0;
}
