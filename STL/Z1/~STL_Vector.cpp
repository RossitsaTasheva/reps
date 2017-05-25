//============================================================================
// Name        : ~STL_Vector.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;
/*1. Write a program that reads from the console
 * a sequence of positive integer numbers.
 *  The sequence ends when the number 0 is entered.
 *   Calculate and print the sum and average of the
 *   elements of the sequence. Use linked list.
*/

void write(vector< unsigned> v) {
	cout << "v contains:";
	for (unsigned i = 0; i < v.size(); i++)
		cout << " " << v[i];
	cout << "\n\n";
}
void read(vector< unsigned> &v) {
	while (true) {

		unsigned s;
		cin >> s;
		if (s == 0) {
			break;
		}
		v.push_back(s);
	}
}
unsigned sum(vector< unsigned> v) {
	unsigned sum = 0;
	for (unsigned i = 0; i < v.size(); i++) {
		sum = sum + v[i];
	}
	return sum;
}

int main() {
	vector< unsigned> v;
	cout << "Enter number" << endl;
	read(v);
	write(v);
	sort(v.begin(), v.end());
	cout<< "Sort is: "<<endl;
	write(v);
	unsigned s = sum(v);
	cout <<"SUM IS: "<<s<<endl;
	double avar;
	avar =(double) s/v.size();
	cout<<avar;
	return 0;
}

