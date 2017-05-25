#include "Address.h"

Address::Address() {
	setStreet("New street");
	setCity("New city");
	setCountry("New country");
	setZipCode(0);
}

Address::Address(string street, string city,
		string country, int zipCode) {
	setStreet(street);
	setCity(city);
	setCountry(country);
	setZipCode(zipCode);
}

void Address::print(){
	cout << getStreet() << " "<< getCity() << " "<< getCountry() << " "
			<< getZipCode() << endl;
}

const string& Address::getCity() const {
	return city;
}

void Address::setCity(const string& city) {
	this->city = city;
}

const string& Address::getCountry() const {
	return country;
}

void Address::setCountry(const string& country) {
	this->country = country;
}

const string& Address::getStreet() const {
	return street;
}

void Address::setStreet(const string& street) {
	this->street = street;
}

int Address::getZipCode() const {
	return zipCode;
}

void Address::setZipCode(int zipCode) {
	this->zipCode = zipCode;
}

Address::~Address() {}
