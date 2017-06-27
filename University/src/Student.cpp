/*
 * Student.cpp
 *
 *  Created on: 22.04.2017 г.
 *      Author: Rossi
 */

#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;


Student::Student(string name ,string egn,vector<unsigned short> grades) :Person(name,egn) {
setGrades(grades);
}
Student::~Student() {
}

const vector<unsigned short>& Student::getGrades() const {
	return grades;
}

void Student::setGrades(const vector<unsigned short>& grades) {
	this->grades = grades;
}

void Student::print() {
	cout<<"|"<<getName()<<"|"<<getEgn()<<"|"<<endl;
	for(unsigned i = 0;i<grades.size();i++){
	cout<<" "<<i+1<<": "<<grades[i]<<endl;
	cout<<"----------------------"<<endl;
	}
}

float Student::getAvarage() {
	float avr=0;
	for(unsigned i = 0;i<grades.size();i++){
		avr+=grades.size();
	}
	return avr/grades.size();
}

void Student::addgrade(const unsigned short & grade) {
	if(grade<2){
		grades.push_back(2);
	}
	else if(grade>6){
		grades.push_back(6);
	}else{
		grades.push_back(grade);
	}
}
