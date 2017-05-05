//============================================================================
// Name        : _LEKA_ATLETIKA.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Athletes.h"
#include "Disciplines.h"
#include "Starts.h"
#include "Time.h"
#include "Date.h"
using namespace std;

/*Да се направи приложение "Съзтезание по лека атлетика".
 *
Имаме атлети (име, фамилия, най-добро постижение, националност),

дисциплини (име, световен рекорд, рекорд на съзтезанието),

стартове (дата, час, дисциплина, участници в старта,

тип (квалификация, четвъртфинал, полуфинал, финал))

След всеки старт трябва да се пази информация за постиженията
на атлетите и съответно кой продължава напред.

Накрая да се изведе крайно класиране.

Да има търсене по име на атлет,
по име на дисциплина (да се извеждат всички стартове и атлети
за тази дисциплина в съзтезанието).

Да се изведе класиране по медали по държави.
 * */

int main() {
	Date g1( 1, 11, 2011 );
	Date g2( 2, 12, 2012 );
	Date g3( 3, 13, 2013 );
	Time t1(11, 11,  11);
	Time t2(12, 12,  12);
	Time t3(13, 13,  13);
	cout<<endl;
	g1.print();
	cout<<endl;
	t1.print();
	cout<<endl;
	Athletes a1("Ivan", "Minev", 20.21,"Bulgarian");
	Athletes a2("Mira", "Dineva", 10.22,"Bulgarian");
	Athletes a3("Gogo", "Ginev", 15.23,"Bulgarian");
	a1.print();
	cout<<endl<<endl;
	Disciplines d1("Running", 34.25, 30.21);
	Disciplines d2("Jump", 1334.25,1230.22);
	Disciplines d3("sprnt", 24.25, 15.23);
	d2.print();
	cout<<endl<<endl;
	vector<Athletes> athAll;
	athAll.push_back(a1);
	athAll.push_back(a2);
	athAll.push_back(a3);

	Starts s1(g1, t1, d1, types[0]);
	Starts s2(g2, t2, d2, types[1]);
	Starts s3(g3, t3, d3, types[2]);
	s1.print();


	return 0;
}
