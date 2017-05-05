/*
 * Athletes.cpp
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#include "Athletes.h"

Athletes::Athletes(string firstName, string secondName, float bestAchicvement,
		string nationality) {
	setFirstName(firstName);
	setSecondName(secondName);
	setBestAchicvement(bestAchicvement);
	setNationality(nationality);
}
Athletes::~Athletes() {}

float Athletes::getBestAchicvement() const {
	return BestAchicvement;
}
void Athletes::setBestAchicvement(float bestAchicvement) {
	BestAchicvement = bestAchicvement;
}

const string& Athletes::getFirstName() const {
	return firstName;
}
void Athletes::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const string& Athletes::getNationality() const {
	return Nationality;
}
void Athletes::setNationality(const string& nationality) {
	Nationality = nationality;
}

const string& Athletes::getSecondName() const {
	return secondName;
}
void Athletes::setSecondName(const string& secondName) {
	this->secondName = secondName;
}



void Athletes::print() {
	cout<<"Athlete is: "<<"|"<<getFirstName()<<" "<<getSecondName()<<"|"<<
			getBestAchicvement()<<"|"<<getNationality()<<"|";

}


