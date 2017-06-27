//============================================================================
// Name        : ~Algorithm_random_shuffle.cpp// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// random_shuffle example / случайно разбъркване
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

// random generator function:
int myrandom(int i) {
	return rand() % i;
}
void write(vector<int> v){
	for (vector<int>::iterator it = v.begin(); it != v.end();
				++it)
			cout << ' ' << *it;
		cout << '\n';
}

int main() {
	srand(unsigned(time(0)));
	vector<int> v;

	// set some values:
	for (int i = 1; i < 10; ++i)
		v.push_back(i); // 1 2 3 4 5 6 7 8 9
	write (v);
	// using built-in random generator:
	random_shuffle(v.begin(), v.end());
	write (v);
	// using myrandom:
	random_shuffle(v.begin(), v.end(), myrandom);

	write (v);

	return 0;
}

