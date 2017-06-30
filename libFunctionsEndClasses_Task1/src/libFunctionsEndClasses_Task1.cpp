//============================================================================
// Name        : libFunctionsEndClasses_Task1.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <iomanip>
#include<string>
#include<sstream>
using namespace std;

string FormatsCurrency(int a,string b){
	 stringstream ss;
	    ss << a <<" "<< b;
	    string str = ss.str();
	    return str;
}

int main() {
string BGL , d,euro;
BGL =	FormatsCurrency(25,"BGL");
d =	FormatsCurrency(100,"&");
euro =	FormatsCurrency(200,"EURO");
cout<<BGL<<endl;
cout<<d<<endl;
cout<<euro<<endl;



/*	ios state(NULL);

	cout << "The answer in decimal is: " << 42 << endl;

	state.copyfmt(cout); // save current formatting
	cout << "In hex: 0x" // now load up a bunch of formatting modifiers
			//Сега заредете куп форматиращи модификатори
			<< hex << uppercase << setw(8) << setfill('0') << 42 // the actual value we wanted to print out
			<< endl;
	cout.copyfmt(state); // Възстановяване на предишното форматиране

//operatiri za stringove
	string a = "abc";
	string b = "klm";

	a += b;
	cout << a << endl;

	char s = a[5];
	cout << s << "2" << endl;

	cout << a + b << endl;

	bool t = a == b;
	bool n = a != b;
	bool h = a < b;

	cout << t << endl;
	cout << n << endl;
	cout << h << endl;

	string x = "hello";
	string y = "ivaylo";

	x.swap(y);
	cout << x << endl << y << endl;

	x.append(y);
	cout << x << endl;

	x.insert(6, " inserted ");
	cout << x << endl;

	x.erase(6, 12);
	cout << x << endl;

	int f = x.find("lo");
	cout << f << endl; //4

	f = x.find("nothing"); //-1
	cout << f << endl;

	x = x.substr(0, 2); //iv
	cout << a << endl;*/

	return 0;
}
