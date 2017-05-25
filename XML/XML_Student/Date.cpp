// Fig. 9.18: Date.cpp
// Member-function definitions for class Date.
#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"
Date::Date( int month, int day, int year ){
	setMonth(month);
	setDay(day);
	setYear(year);
}
void Date::print() 
{ 
   cout << getMonth()<< '/' << getDay() << '/' << getYear()<<" | ";
}
int Date::getDay() const {return day;}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getMonth() const {return month;}

void Date::setMonth(int month) {this->month = month;}

int Date::getYear() const {	return year;}

void Date::setYear(int year) {	this->year = year;}
