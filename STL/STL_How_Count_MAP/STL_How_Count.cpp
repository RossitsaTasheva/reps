//============================================================================
// Name        : STL_How_Count.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main() {

	//katia 234
	//lili  235
	//key(unique)  - value

	string text = "Here in Sofia we are here in Sofia Sofia  is the capital.";

	//not in map => word - 1
	// in map => get value(word) ++
	vector<string> words;
	words.push_back("Here");
	words.push_back("in");
	words.push_back("Sofia");
	words.push_back("we");
	words.push_back("are");
	words.push_back("here");
	words.push_back("in");
	words.push_back("Sofia");
	words.push_back("Sofia");
	words.push_back("is");
	words.push_back("the");
	words.push_back("the");
	words.push_back("capital");

	map<string, int> countingWords;
	for (unsigned i = 0; i < (unsigned) words.size(); i++) {
		string key = words[i];
		int val = 1;
		if (countingWords.find(key) != countingWords.end()) {
			val = countingWords[key];
			val++;
			countingWords[key] = val;
		} else {
			countingWords[key] = val;	// insert ima metod
		}
	}
	//izmegdane
	map<string, int>::iterator it;
	for (it = countingWords.begin(); it != countingWords.end(); it++) {
		//vrashta ni iterator kam 1-vi element
		cout << it->first << " => " << it->second << endl;

	}
	return 0;
}
