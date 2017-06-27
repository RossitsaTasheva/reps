/*
 * Student.h
 *
 *  Created on: 22.04.2017 г.
 *      Author: Rossi
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include "Person.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Student: public Person {
public:

	Student(string name = " ",string egn = " ",vector<unsigned short> grades  =
			vector<unsigned short>());

	void print();
	float getAvarage();
	void addgrade(const unsigned short& grade);

	virtual ~Student();
	const vector<unsigned short>& getGrades() const;
	void setGrades(const vector<unsigned short>& grades);

private:
	vector<unsigned short> grades;
};

#endif /* STUDENT_H_ */
