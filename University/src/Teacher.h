/*
 * Teacher.h
 *
 *  Created on: 29.04.2017 г.
 *      Author: Rossi
 */

#ifndef TEACHER_H_
#define TEACHER_H_
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Teacher : public Person {
public:
	Teacher(string name = " ",string egn = " ",string discipline = " ",
 short experiense = 0);
	virtual ~Teacher();
	virtual void print();
	const string& getDiscipline() const;
	void setDiscipline(const string& discipline);
	unsigned short getExperiense() const;
	void setExperiense(unsigned short experiense);

private:
	string discipline;
	unsigned short experiense;
};

#endif /* TEACHER_H_ */
