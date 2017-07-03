//============================================================================
// Name        : Time_Task7.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <cwchar>
#include <time.h>
using namespace std;



void currentDateTime(){
	time_t rawtime;
	  struct tm * timeinfo;

	  time ( &rawtime );
	  timeinfo = localtime ( &rawtime );
	  cout <<"Date/time is: "<< asctime (timeinfo);
}

int main ()
{
	currentDateTime();

  return 0;
}
/*char* asctime(const struct tm *timeptr)
{
  static const char wday_name[][4] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  };
  static const char mon_name[][4] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };
  static char result[26];
  sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
    wday_name[timeptr->tm_wday],
    mon_name[timeptr->tm_mon],
    timeptr->tm_mday, timeptr->tm_hour,
    timeptr->tm_min, timeptr->tm_sec,
    1900 + timeptr->tm_year);
  return result;
}*/
