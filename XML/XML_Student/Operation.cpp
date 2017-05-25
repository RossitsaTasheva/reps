/*
 * Operation.cpp
 *
 *  Created on: 23.05.2017 г.
 *      Author: Rossi
 */

#include "Operation.h"

Operation::Operation() {
}

Operation::~Operation() {
}
// Функция, която чете XML файл и го записва във вектор
//fileName се подава в мейна :  //Operation op;
								//op.Traverse( "XMLfile.xml");

void Operation::Traverse(const char* fileName) {
	pugi::xml_document doc;
	if (!doc.load_file(fileName)) {
		cout << "No XML file found";
	}
	pugi::xml_node students = doc.child("students");

//1-----------------------------------------------------------
	for (pugi::xml_node student = students.child("student"); student;
			student = student.next_sibling("student")) {

		/* Само ако искаме да дисплейваме атрибути
		 * // node attribute
		 for (pugi::xml_attribute attr = book.first_attribute(); attr; attr =
		 attr.next_attribute()) {
		 cout << " id " << attr.name() << "=" << attr.value() << " ";
		 }*/

		//node child nodes
		string astreet = student.child("address").child("street").text().as_string();
		string acity =student.child("address").child("city").text().as_string();
		string acountry =student.child("address").child("country").text().as_string();
		int azipCode = student.child("address").child("zipCode").text().as_int();

		string sname = student.child("name").text().as_string();
		int sage = student.child("age").text().as_int();
		string smajor = student.child("major").text().as_string();
		//Обект от клас Автор
		Address *aa = new Address(astreet,acity,acountry,azipCode);
		//Обект  от клас Книга
		Student *st = new Student(sname, sage,smajor,*aa);
		//Пълним вектора
		stud.push_back(st);

	}
}

void Operation::print() {
	for (unsigned i = 0; i < stud.size(); i++) {
		stud[i]->print();
	}
}
