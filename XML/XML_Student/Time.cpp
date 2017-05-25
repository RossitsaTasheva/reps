// Fig. 9.2: Time.cpp
// Member-function definitions for class Time.

#include "Time.h"
#include <iomanip>
#include <iostream>
using namespace std;

Time::Time(int hour,int minute, int second)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}
// (HH:MM:SS)
void Time::print()
{
   cout << setfill( '0' ) << setw( 2 ) << hour << ":" 
      << setw( 2 ) << minute << ":" << setw( 2 ) << second<<" | ";
}

int Time::getHour() const {
	return  hour ;
}
void Time::setHour(int hour) {
	this->hour = ( hour >= 0 && hour < 24 ) ? hour : 0;
}

int Time::getMinute() const {
	return minute;
}

void Time::setMinute(int minute) {
	this->minute = ( minute >= 0 && minute < 60 ) ? minute : 0;
}

int Time::getSecond() const {
	return second;
}

void Time::setSecond(int second) {
	this->second = ( second >= 0 && second < 60 ) ? second : 0;
}
