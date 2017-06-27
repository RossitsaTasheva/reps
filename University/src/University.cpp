/*
 * University.cpp
 *
 *  Created on: 23.04.2017 г.
 *      Author: Rossi
 */

#include "University.h"

University::University(vector<Teacher *>& teachers,
		vector<Student*>& students) {
	setStudents(students);
	setTeachers(teachers);
}
University::~University() {
}
const vector<Student*>& University::getStudents() const {
	return students;
}
void University::setStudents(const vector<Student*>& students) {
	this->students = students;
}
const vector<Teacher*>& University::getTeachers() const {
	return teachers;
}
void University::setTeachers(const vector<Teacher*>& teachers) {
	this->teachers = teachers;
}

vector<unsigned> University::searchTeacher(const string& name,
		const string& egn, const string& discipline,
		const short & experiense) const {
	bool ignore[4] = { 0 };
	if (name == " ") {
		ignore[0] = true;
	}
	if (egn == " ") {
		ignore[1] = true;
	}
	if (discipline == " ") {
		ignore[2] = true;
	}
	if (experiense == 0) {
		ignore[3] = true;
	}
	vector<unsigned> found;
	for (unsigned i = 0; i < teachers.size(); i++) {
		if ((ignore[0] || teachers[i]->getName() == name)
				&& (ignore[1] || teachers[i]->getEgn() == egn)
				&& (ignore[2] || teachers[i]->getDiscipline() == discipline)
				&& (ignore[3] || teachers[i]->getExperiense() == experiense)) {
			found.push_back(i);
		}
	}
	return found;
}
vector<unsigned> University::searchStudent(const string& name,
		const string& egn, const unsigned short& avarage) const {
	bool ignore[3] = { 0 };
	if (name == " ") {
		ignore[0] = true;
	}
	if (egn == " ") {
		ignore[1] = true;
	}
	if (avarage == 0) {
		ignore[2] = true;
	}

	vector<unsigned> found;
	for (unsigned i = 0; i < students.size(); i++) {
		if ((ignore[0] || students[i]->getName() == name)
				&& (ignore[1] || students[i]->getEgn() == egn)
				&& (ignore[2] || students[i]->getAvarage() == avarage)) {
			found.push_back(i);
		}
	}
	return found;
}
void University::addStudent(Student *student) {
	for (unsigned i = 0; i < students.size(); i++) {
		if (students[i]->getEgn() == student->getEgn())
			return;
		students.push_back(student);
	}
}
void University::addTeacher(Teacher *teacher) {
	for (unsigned i = 0; i < teachers.size(); i++) {
		if (teachers[i]->getEgn() == teacher->getEgn())
			return;
		teachers.push_back(teacher);
	}
}

string University::print() {
	string str = "";
	str+= "\nStudents:\n";
	for (unsigned i = 0; i < students.size(); i++) {
		str+=  students[i]->print();
	}
	str+= "\nTeachers:\n";
	for (unsigned i = 0; i < teachers.size(); i++) {
		str+=  teachers[i]->print();
	}
	return str;
}
