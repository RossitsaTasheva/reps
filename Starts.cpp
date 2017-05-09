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
Starts::Starts() {
		setType(NOtype);
		setDate(0);
		setTime(0);

}
Starts::Starts(Date &date, Time& time, Disciplines& dis,vector<Athletes*> &athStarts, types type):
		date(date),time(time),dis(dis) {
	setType(type);
	setDis(dis);
	setDate(date);
	setTime(time);
	setAthStarts(athStarts);
}
Starts::~Starts() {}
const vector<Athletes*>& Starts::getAthStarts() const {
	return athStarts;}



void Starts::setAthStarts(const vector<Athletes*>& athStarts) {
	this->athStarts = athStarts;}

const Date& Starts::getDate() const {return date;}
void Starts::setDate(const Date& date) {
	this->date = date;}

const Disciplines& Starts::getDis() const {	return dis;}
void Starts::setDis(const Disciplines& dis) {this->dis = dis;}

const Time& Starts::getTime() const {return time;}
void Starts::setTime(const Time& time) {
	this->time = time;
}



void Starts::inputAtlet(Athletes* atlet) {

	athStarts.push_back(atlet);
}
string Starts::typePr() {
string res;
	  switch (Starts::type) {
			case NOtype:	res = "NOtype";	break;
			case Qualification:	res = "Qualification";	break;
			case Quarterfinals:res = "Quarterfinals";	break;
			case Semifinals:res = "Semifinals";	break;
			case Final: res ="Final";	break;
			default:cout << "Error" << endl;
			}
	return res;
}
void Starts::print() {
	cout<<"Starts is: "<<endl;
	date.print();
	time.print();
	dis.print();
	cout<<typePr()<<endl;
	for(unsigned i=0;i<athStarts.size();i++ ){
				athStarts[i]->print();
				cout << "|"<<endl;
			}
}

/*vector<unsigned> Starts::searchAthlet(const string& firstName,
		const string& secondName, const float& bestAchicvement,
		const string& nationality) const {
	bool ignore[4]={0};
	if(firstName =="")ignore[0] = true;
	if(secondName =="")ignore[1] = true;
	if(bestAchicvement ==0.0)ignore[2] = true;
	if(nationality =="")ignore[3] = true;
	vector<unsigned> found;
	for(unsigned i=0;i<athStarts.size();i++){
			if((ignore[0] || athStarts[i]->getFirstName() == firstName )&&
			(ignore[1] || athStarts[i]->getSecondName() == secondName)&&
			(ignore[2] || athStarts[i]->getBestAchicvement() == bestAchicvement)&&
			(ignore[3] || athStarts[i]->getNationality() == nationality)){
			found.push_back(i);
		}
	}
	return found;
}*/

Starts::types Starts::getType() const {
	return type;
}

void Starts::searchByName(string firstName) {
	for(unsigned i=0;i<athStarts.size();i++){
		if(athStarts[i]->getFirstName()==firstName){
			athStarts[i]->print();
		}
	}
}



void Starts::setType(types type) {
	this->type = type;
}
