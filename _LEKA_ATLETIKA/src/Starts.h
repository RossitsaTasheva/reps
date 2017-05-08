/*
 * Starts.h
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#ifndef STARTS_H_
#define STARTS_H_
#include <iostream>
#include <vector>
#include "Time.h"
#include "Date.h"
#include "Disciplines.h"
#include "Athletes.h"
#include <string>
using namespace std;
//const string types[]={"NO type","Qualification","Quarterfinals","Semifinals","Final"};
enum types {NOtype,Qualification,Quarterfinals,Semifinals,Final};
class Starts {

public:
	Starts();
	Starts(Date &, Time& , Disciplines&  ,vector<Athletes*>& , types);

	virtual ~Starts();

	void print();

	void inputAtlet(Athletes *athStarts);

	vector<unsigned> searchAthlet(const string& firstName = "", const string &secondName = "",const float& bestAchicvement = 0.0,
	const string &nationality = "")const;

	const Date& getDate() const;
	void setDate(const Date& date);

	const Disciplines& getDis() const;
	void setDis(const Disciplines& dis);

	const Time& getTime() const;
	void setTime(const Time& time);

	types getType() const;
		void setType(types type);

	const vector<Athletes*>& getAthStarts() const;
	void setAthStarts(const vector<Athletes*>& athStarts);

private:
	Date date;
	Time time;
	Disciplines dis;
	vector<Athletes*> athStarts;
	types type;

};

#endif /* STARTS_H_ */
