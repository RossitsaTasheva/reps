/*
 * AthletesOperations.h
 *
 *  Created on: 7.05.2017 г.
 *      Author: Rossi
 */

#ifndef ATHLETESOPERATIONS_H_
#define ATHLETESOPERATIONS_H_
#include <iostream>
#include <vector>
#include "Starts.h"
#include "Time.h"
#include "Date.h"
#include "Disciplines.h"
#include "Athletes.h"
#include <string>
using namespace std;

class AthletesOperations {
public:
	AthletesOperations();

	virtual ~AthletesOperations();
	void print();

	void inputAthStarts(Athletes *a);

	void inputAthAll(Athletes *a);

	void inputAllStarts(Starts *s);

	void searchBySecondName(string);
	const vector<Starts*>& getAllStarts() const;
	void setAllStarts(const vector<Starts*>& allStarts);
	const vector<Athletes*>& getAthAll() const;
	void setAthAll(const vector<Athletes*>& athAll);
	const vector<Disciplines*>& getDiscipline() const;
	void setDiscipline(const vector<Disciplines*>& discipline);

private:
		vector<Disciplines*> discipline;
		vector<Athletes*> athAll;
		vector<Starts*> allStarts;

};

#endif /* ATHLETESOPERATIONS_H_ */
