/*
 * University.h
 *
 *  Created on: 23.04.2017 г.
 *      Author: Rossi
 */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include "Teacher.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class University {

public:
	University(vector<Teacher*>&teacher, vector<Student*>&student);
	const vector<Student*>& getStudents() const;
	void setStudents(const vector<Student*>& students);
	const vector<Teacher*>& getTeachers() const;
	void setTeachers(const vector<Teacher*>& teachers);

	//добавяне на студент към списъка
	void addStudent(Student *student);
	//добавяне на преподавател към списъка
	void addTeacher(Teacher *teacher);

	//търсене на студент по име , egn i avarage
	vector<unsigned>searchStudent(const string& name = " ",const string &egn = " ",
		const unsigned short& avarage  = 0) const;
	//търсене на teachers по име , egn i avarage
	vector<unsigned>searchTeacher(const string& name = " ",const string &egn = " ",
			const string &discipline = " ",const short &experiense = 0) const;
	string print();
	virtual ~University();

private:
	vector<Student*> students;
	vector<Teacher*> teachers;
};

#endif /* UNIVERSITY_H_ */
