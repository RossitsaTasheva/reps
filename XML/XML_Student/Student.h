/*
 * Student.h
 *
 *  Created on: 6.04.2017 �.
 *      Author: Rossi
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include "Address.h"
#include <string>
using namespace std;

class Student {
public:
	Student();
	Student(string, int, string , Address&);

	virtual ~Student();


	void print();
	double SrUspeh();
	void MAX();
	void MIN();
	int br6();
	int br2();

	const Address& getAddress() const;
	void setAddress(const Address& address);

	int getAge() const;
	void setAge(int age);

	const string& getName() const;
	void setName(const string& name);

	const string& getMajor() const;
	void setMajor(const string& major);

	//const int* getOarr() const;

private:
	string name;
	int age;
	string major;
	Address address;
	//int oarr[10];
};

#endif /* STUDENT_H_ */
