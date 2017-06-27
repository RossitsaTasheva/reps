/*
 * Teacher.cpp
 *
 *  Created on: 29.04.2017 г.
 *      Author: Rossi
 */

#include "Teacher.h"

Teacher::Teacher(string name, string egn, string discipline, short experiense):
Person(name,egn) {
	setDiscipline(discipline);
	setExperiense(experiense);
}

Teacher::~Teacher() {

}

const string& Teacher::getDiscipline() const {
	return discipline;
}

void Teacher::setDiscipline(const string& discipline) {
	this->discipline = discipline;
}

unsigned short Teacher::getExperiense() const {
	return experiense;
}

void Teacher::setExperiense(unsigned short experiense) {
	this->experiense = experiense;
}
void Teacher::print() {
	Person::print();
	cout<<"|"<<getDiscipline()<<"|"<<getDiscipline()<<"|";
}
