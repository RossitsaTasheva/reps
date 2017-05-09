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
#include "AthletesOperations.h"
#include "Starts.h"
#include "Time.h"
#include "Date.h"
using namespace std;

/*Да се направи приложение "Съзтезание по лека атлетика".
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

	vector<Athletes*> athStarts;
	vector<Athletes*> athAll;
	vector<Starts*> allStarts;

	Date date1(1, 11, 2011);
	Date date2(2, 12, 2012);
	Date date3(3, 13, 2013);
	Date date4(4, 14, 2014);
	Date date5(5, 15, 2015);
	Time time1(11, 11, 11);
	Time time2(12, 12, 12);
	Time time3(13, 13, 13);
	Time time4(14, 14, 14);
	Time time5(15, 15, 15);

	Athletes a1("Ivan", "Minev", 20.21, "Bulgarian");
	athAll.push_back(&a1);
	Athletes a11("Mira", "Ivanova", 12.21, "Bulgarian");
	athAll.push_back(&a11);
	Athletes a12("Katia", "Petrova", 13.12, "Bulgarian");
	athAll.push_back(&a12);
	Athletes a13("Georgi", "Dimitrov", 15.33, "Bulgarian");
	athAll.push_back(&a13);
	Athletes a14("Teodor", "Tashev", 14.44, "Bulgarian");
	athAll.push_back(&a14);
	Athletes a15("Dimitar", "Nenov", 12.55, "Bulgarian");
	athAll.push_back(&a15);

	Athletes a2("Lena", "Petuha", 10.22, "Russia");
	athAll.push_back(&a2);
	Athletes a21("Ivan", "Ivanich", 11.28, "Russia");
	athAll.push_back(&a21);
	Athletes a22("Nadia", "Shkilnuk", 12.27, "Russia");
	athAll.push_back(&a22);
	Athletes a23("Denis", "Letvinenko", 13.24, "Russia");
	athAll.push_back(&a23);
	Athletes a24("Vitalii", "Puka", 14.22, "Russia");
	athAll.push_back(&a24);
	Athletes a25("Natashe", "Voloshuk", 14.13, "Russia");
	athAll.push_back(&a25);

	Athletes a3("Denis", "Gerkh", 15.23, "USA");
	athAll.push_back(&a3);
	Athletes a31("Ser", "Gulden", 15.23, "USA");
	athAll.push_back(&a31);
	Athletes a32("Verg", "Sprler", 15.23, "USA");
	athAll.push_back(&a32);
	Athletes a33("Denir", "Herim", 15.23, "USA");
	athAll.push_back(&a33);
	Athletes a34("Duk", "Gifred", 15.23, "USA");
	athAll.push_back(&a34);
	Athletes a35("Siera", "Gertg", 15.23, "USA");
	athAll.push_back(&a35);

	cout << endl << endl;
	Disciplines dis1("sprnt200", 34.25, 30.21);
	Disciplines dis2("Jump", 1334.25, 1230.22);
	Disciplines dis3("sprnt100", 24.25, 15.23);
	dis1.print();
	cout << endl << endl;

	Starts start1(date1, time1, dis1, athStarts,Starts::Qualification);
	start1.inputAtlet(&a1);
	start1.inputAtlet(&a2);
	start1.inputAtlet(&a3);
	Starts start2(date2, time2, dis2, athStarts, Starts::Semifinals);
	start2.inputAtlet(&a11);
	start2.inputAtlet(&a21);
	start2.inputAtlet(&a31);
	Starts start3(date3, time3, dis3, athStarts,Starts::Quarterfinals);
	start3.inputAtlet(&a12);
	start3.inputAtlet(&a22);
	start3.inputAtlet(&a32);
	start1.print();
	cout<<endl<<"~~~~~~~~~~~~~~"<<endl;
	start2.print();
	cout<<endl<<"~~~~~~~~~~~~~~"<<endl;
	start3.print();
	cout<<endl<<"~~~~~~~~~~~~~~"<<endl;



	return 0;
}
