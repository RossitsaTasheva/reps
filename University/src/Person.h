/*
 * Person.h
 *
 *  Created on: 29.04.2017 г.
 *      Author: Rossi
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
using namespace std;

class Person {
private:
	string name;
	string egn;
public:
	Person(const string &name,const string &egn);

	virtual void print();

	virtual ~Person();

	const string& getEgn() const;
	void setEgn(const string& egn);

	const string& getName() const;
	void setName(const string& name);
};

#endif /* PERSON_H_ */
