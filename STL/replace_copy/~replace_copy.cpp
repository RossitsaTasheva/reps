//============================================================================
// Name        : ~replace_copy.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// replace_copy example
#include <iostream>     // std::cout
#include <algorithm>    // std::replace_copy
#include <vector>       // std::vector
using namespace std;

void write(vector<int> v) {
	cout << "v contains:";
	for (unsigned i = 0; i < v.size(); i++)
		cout << " " << v[i];
	cout << "\n\n";
}

int main() {
	int arr[] = { 10, 20, 30, 30, 20, 10, 10, 20 };

	vector<int> v(8);
	write(v);
	replace_copy(arr, arr + 8, v.begin(), 20, 99);

	write(v);

	return 0;
}
