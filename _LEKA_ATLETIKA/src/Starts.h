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
const string types[]={"NO type","Qualification","Quarterfinals","Semifinals","Final"};
class Starts {

public:
	Starts(Date &date, Time& time, Disciplines& dis , string type);

	virtual ~Starts();

	void print();

	void inputAtlet(Athletes&);

	const vector<Athletes>& getAthStarts() const;
	void setAthStarts(const vector<Athletes>& athStarts);

	const Date& getDate() const;
	void setDate(const Date& date);

	const Disciplines& getDis() const;
	void setDis(const Disciplines& dis);

	const Time& getTime() const;
	void setTime(const Time& time);

	const string& getType() const;
	void setType(const string& type);

private:
	Date date;
	Time time;
	Disciplines dis;
	vector<Athletes> athStarts;
	string type;
};

#endif /* STARTS_H_ */
