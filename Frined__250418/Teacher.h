#pragma once
#include "Library.h"
#include "Exam.h"

class Teacher
{
public:
	Teacher();
	Teacher(string name, string surname, int age, string gender, string faculty);
	Teacher(const Teacher &obj);
	virtual~Teacher();
	string getSname() { return surname; }
private:
	string name;
	string surname;
	int age;
	string gender;
	string faculty;
	friend istream& operator >> (istream& in, Teacher &teacher); // ����� ��� �������� ����� �����
	friend bool operator == (Teacher obj1, Teacher obj2);
	friend bool operator == (string & str, Teacher obj);
	friend bool operator != (Teacher obj1, Teacher obj2);
	friend bool operator != (string & str, Teacher obj);
	friend bool operator > (Teacher obj1, Teacher obj2);
	friend bool operator > (int str, Teacher obj);
	friend bool operator < (Teacher obj1, Teacher obj2);
	friend bool operator < (int str, Teacher obj);
	friend void printTeachers(Teacher *teacher, int countOfTeachers);
	friend void printTecaher(Teacher &teacher);
	friend class Exam;
};

