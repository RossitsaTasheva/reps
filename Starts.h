/*
 * Starts.h
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#ifndef STARTS_H_
#define STARTS_H_
#include <iostream>
#include <string>
#include <vector>
#include "Time.h"
#include "Date.h"
#include "Disciplines.h"
#include "Athletes.h"
#include <string>
using namespace std;
//const string types[]={"NO type","Qualification","Quarterfinals","Semifinals","Final"};

class Starts {

public:
	enum types {NOtype ,Qualification ,Quarterfinals ,Semifinals,Final };
	Starts();
	Starts(Date &, Time& , Disciplines&  ,vector<Athletes*>& , types);

	virtual ~Starts();

	void print();

	void inputAtlet(Athletes *athStarts);
	void searchByName(string);
	vector<unsigned> searchAthlet(const string& firstName = "", const string &secondName = "",const float& bestAchicvement = 0.0,
	const string &nationality = "")const;
	string typePr();
	const Date& getDate() const;
	void setDate(const Date& date);

	const Disciplines& getDis() const;
	void setDis(const Disciplines& dis);

	const Time& getTime() const;
	void setTime(const Time& time);



	const vector<Athletes*>& getAthStarts() const;
	void setAthStarts(const vector<Athletes*>& athStarts);
	types getType() const;
	void setType(types type);

private:
	Date date;
	Time time;
	Disciplines dis;
	vector<Athletes*> athStarts;
	types type;

};

#endif /* STARTS_H_ */
