// Fig. 9.17: Date.h
// Declaration of class Date.
// Member functions are defined in Date.cpp

#ifndef DATE_H
#define DATE_H
class Date 
{
public:
   Date( int month = 1, int day = 1, int year = 2000 );

   void print();

	int getDay() const;
	void setDay(int day);

	int getMonth() const;
	void setMonth(int month);

	int getYear() const;
	void setYear(int year);

private:
   int month;
   int day;
   int year;
};

#endif

