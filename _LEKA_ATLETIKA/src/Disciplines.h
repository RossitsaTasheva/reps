/*
 * Disciplines.h
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#ifndef DISCIPLINES_H_
#define DISCIPLINES_H_
#include <iostream>
#include <string>
using namespace std;

class Disciplines {
public:
	Disciplines(string name = "",float worldRecord = 0,float raceRecord = 0);

	void print();
	virtual ~Disciplines();

	const string& getName() const;
	void setName(const string& name);

	float getRaceRecord() const;
	void setRaceRecord(float raceRecord);

	float getWorldRecord() const;
	void setWorldRecord(float worldRecord);

private:
	string name;
	float worldRecord;
	float raceRecord;
};

#endif /* DISCIPLINES_H_ */
