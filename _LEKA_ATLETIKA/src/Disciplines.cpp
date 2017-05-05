/*
 * Disciplines.cpp
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#include "Disciplines.h"

Disciplines::Disciplines(string name, float worldRecord, float raceRecord) {
	setName(name);
	setWorldRecord(worldRecord);
	setRaceRecord(raceRecord);

}

void Disciplines::print() {
	cout<<"Discipline is: "<<"|"<<getName()<<"|"<<getWorldRecord()
			<<"|"<<getRaceRecord()<<"|"<<endl;
}

Disciplines::~Disciplines() {}

const string& Disciplines::getName() const {
	return name;
}
void Disciplines::setName(const string& name) {
	this->name = name;
}

float Disciplines::getRaceRecord() const {
	return raceRecord;
}
void Disciplines::setRaceRecord(float raceRecord) {
	this->raceRecord = raceRecord;
}

float Disciplines::getWorldRecord() const {
	return worldRecord;
}
void Disciplines::setWorldRecord(float worldRecord) {
	this->worldRecord = worldRecord;
}
