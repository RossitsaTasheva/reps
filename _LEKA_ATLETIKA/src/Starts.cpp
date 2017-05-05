/*
 * Starts.cpp
 *
 *  Created on: 4.05.2017 г.
 *      Author: Rossi
 */

#include "Starts.h"
#include "Date.h"
#include <iostream>
using namespace std;

Starts::Starts(Date &date, Time& time, Disciplines& dis, string type):date(date),time(time),dis(dis) {
}

Starts::~Starts() {}
const vector<Athletes>& Starts::getAthStarts() const {
	return athStarts;
}
void Starts::setAthStarts(const vector<Athletes>& athStarts) {
	this->athStarts = athStarts;
}
const Date& Starts::getDate() const {
	return date;
}
void Starts::setDate(const Date& date) {
	this->date = date;
}
const Disciplines& Starts::getDis() const {
	return dis;
}
void Starts::setDis(const Disciplines& dis) {
	this->dis = dis;
}
const Time& Starts::getTime() const {
	return time;
}


void Starts::print() {
	cout<<"Starts is: "<<type<<endl;
	date.print();
	time.print();
	dis.print();
	for(unsigned i=0;i<=athStarts.size();i++ ){
		athStarts[i];
	}
}
void Starts::inputAtlet(Athletes&ath) {
	athStarts.push_back(ath);
}

void Starts::setTime(const Time& time) {
	this->time = time;
}

const string& Starts::getType() const {
	return type;
}

void Starts::setType(const string& type) {
	this->type = type;
}
