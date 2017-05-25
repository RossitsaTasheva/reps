#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <iostream>
#include <string>
using namespace std;

class Address {
public:
	Address();
	Address(string, string, string, int);

	void print();

	virtual ~Address();

	const string& getCity() const;
	void setCity(const string& city);

	const string& getCountry() const;
	void setCountry(const string& country);

	const string& getStreet() const;
	void setStreet(const string& street);

	int getZipCode() const;
	void setZipCode(int zipCode);

private:
	string street;
	string city;
	string country;
	int zipCode;
};

#endif /* ADDRESS_H_ */
