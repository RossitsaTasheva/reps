/*
 * Student.cpp
 *
 *  Created on: 6.04.2017 �.
 *      Author: Rossi
 */

#include "Student.h"


Student::Student():address() {
		setName("N");
		setAge(0);
		setMajor("N");
	//for (int i = 0; i < 10; i++) {
		//this->oarr[i] = 0;
	//}
}
Student::Student(string name, int age,string major, Address& address):address(address) {
	setName(name);
	setAge(age);
	setMajor(major);
	//for (int i = 0; i < 10; i++) {
		//this->oarr[i] = oarr[i];

	//}

}
Student::~Student() {

}

void Student::print() {
	cout << endl;
	cout << "Student name is: " << getName() << endl;
	cout << "Student age is :" << getAge() << endl;
	cout << "Student major is :" << getMajor() << endl;
	cout << "Student Address is: " << endl;
	address.print();
	//cout << "Otsenki is: ";
	//for (int i = 0; i < 10; i++) {
		//cout << this->oarr[i];
	//}
	cout << endl;
}
/*
double Student::SrUspeh() {
	double sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += oarr[i];
	}
	return sum / 10;
}

void Student::MAX() {
	int buf, max;
	cout << endl << endl;
	for (int i = 10 - 1; i > 0; i--) {
		max = 0;
		for (int j = 0; j < i + 1; j++)
			if (this->oarr[j] > oarr[max])
				max = j;
		buf = this->oarr[i];
		oarr[i] = oarr[max];
		oarr[max] = buf;
	}
	for (int i = 0; i < 10; i++) {
		cout << "A[" << i << "]=>";
		cout << this->oarr[i] << endl;
	}
	cout << endl << endl;

}

void Student::MIN() {
	int buf, min;
	cout << endl << endl;
	for (int i = 10 - 1; i > 0; i--) {
		min = 0;
		for (int j = 0; j < i + 1; j++)
			if (this->oarr[j] < oarr[min])
				min = j;
		buf = this->oarr[i];
		oarr[i] = oarr[min];
		oarr[min] = buf;
	}
	for (int i = 0; i < 10; i++) {
		cout << "A[" << i << "]=>";
		cout << this->oarr[i] << endl;
	}
	cout << endl << endl;
}

int Student::br6() {
	int br6 = 0;
	for (int i = 0; i < 10; i++) {
		if (oarr[i] == 6) {
			br6++;
		}
	}
	return br6;

}

int Student::br2() {
	int br2;
	for (int i = 0; i < 10; i++) {
		if (oarr[i] == 2) {
			br2++;
		}
	}
	return br2;

}*/

const Address& Student::getAddress() const {
	return address;
}

void Student::setAddress(const Address& address) {
	this->address = address;
}

int Student::getAge() const {
	return age;
}

void Student::setAge(int age) {
	this->age = age;
}

const string& Student::getName() const {
	return name;
}

void Student::setName(const string& name) {
	this->name = name;
}

const string& Student::getMajor() const {
	return major;
}

void Student::setMajor(const string& major) {
	this->major = major;
}
//const int* Student::getOarr() const {
	///return oarr;
//}
