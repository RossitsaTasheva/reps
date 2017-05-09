/*
 * AthletesOperations.cpp
 *
 *  Created on: 7.05.2017 г.
 *      Author: Rossi
 */

#include "AthletesOperations.h"

AthletesOperations::AthletesOperations() {}

AthletesOperations::~AthletesOperations() {}


void AthletesOperations::searchBySecondName(string secondName) {
	for(unsigned i =0;i<athAll.size();i++){
		if(athAll[i]->getSecondName()==secondName){
			athAll[i]->print();
		}
	}
}

const vector<Starts*>& AthletesOperations::getAllStarts() const {
	return allStarts;
}

void AthletesOperations::setAllStarts(const vector<Starts*>& allStarts) {
	this->allStarts = allStarts;
}

const vector<Athletes*>& AthletesOperations::getAthAll() const {
	return athAll;
}

void AthletesOperations::setAthAll(const vector<Athletes*>& athAll) {
	this->athAll = athAll;
}

const vector<Disciplines*>& AthletesOperations::getDiscipline() const {
	return discipline;
}

void AthletesOperations::setDiscipline(const vector<Disciplines*>& discipline) {
	this->discipline = discipline;
}
/*vector<unsigned> AthletesOperations::searchAthlet(const string& firstName,
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
