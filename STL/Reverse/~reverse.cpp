//============================================================================
// Name        : ~reverse.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//3. Write a program that reads N integers from
//the console and reverses them .

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void write(vector<int> v) {
	cout << "v contains:";
	for (unsigned i = 0; i < v.size(); i++)
		cout << " " << v[i];
	cout << "\n\n";
}
vector<int> read(int n) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin>>a;
		v.push_back(a);
	}
	return v;
}
void reverse(vector<int> &v) {
	vector<int>::const_reverse_iterator reverseIt;
	for (reverseIt = v.rbegin(); reverseIt != v.rend(); ++reverseIt)
		cout << *reverseIt << ' ';
	cout << endl;
}

int main() {
	int n;
	cout << "ENter size vector : " << endl;
	cin >> n;
	vector <int> v;
	v =read(n);
	write(v);
	reverse(v);

	return 0;
}

