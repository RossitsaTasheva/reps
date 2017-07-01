//============================================================================
// Name        : libRoundDouble.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <ctgmath>
using namespace std;
/*3. lib function to round a double to a specific number
 * of digits (including after / before comma),
 *  that produces double (not string) */

double Round(double x, int p)
{
    if (x != 0.0) {
        return ((floor((fabs(x)*pow(double(10.0),p))+0.5))/pow(double(10.0),p))*(x/fabs(x));
    } else {
        return 0.0;
    }
}

int main() {
	double a;
	a = Round(15.25687485, -1);
	cout <<"---"<<a<<"---"<<endl;

	return 0;
}
