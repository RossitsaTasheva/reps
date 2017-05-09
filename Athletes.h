/*
 * Athletes.h
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#ifndef ATHLETES_H_
#define ATHLETES_H_
#include <iostream>
#include <string>
using namespace std;

class Athletes {
public:
	Athletes(string firstName = "", string secondName= "",
			float BestAchicvement = 0.0 , string Nationality= "");

	void print();

	virtual ~Athletes();

	float getBestAchicvement() const;
	void setBestAchicvement(float bestAchicvement);

	const string& getFirstName() const;
	void setFirstName(const string& firstName);

	const string& getNationality() const;
	void setNationality(const string& nationality);

	const string& getSecondName() const;
		void setSecondName(const string& secondName);

private:
	string firstName;
	string secondName;
	float BestAchicvement;
	string Nationality;
};

#endif /* ATHLETES_H_ */
