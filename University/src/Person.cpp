/*
 * Person.cpp
 *
 *  Created on: 29.04.2017 г.
 *      Author: Rossi
 */

#include "Person.h"

Person::Person(const string &name,const string &egn) {
	setName(name);
	setEgn(egn);

}

Person::~Person() {
}

const string& Person::getEgn() const {
	return egn;
}

void Person::setEgn(const string& egn) {
	this->egn = egn;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& name) {
	this->name = name;
}
void Person::print() {
cout <<endl<<getName()<<"|"<<getEgn()<<"|";
}
