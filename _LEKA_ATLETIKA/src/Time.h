// Fig. 9.1: Time.h
// Declaration of class Time.
// Member functions are defined in Time.cpp

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time 
{
public:
   Time( int hour = 0,int minute=0, int second =0);

   void print();

	int getHour() const;
	void setHour(int hour);

	int getMinute() const;
	void setMinute(int minute);

	int getSecond() const;
	void setSecond(int second);

private:
   int hour;
   int minute;
   int second;
};

#endif

