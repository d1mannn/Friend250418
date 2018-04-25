#pragma once
#include "Library.h"
class Teacher
{
public:
	Teacher();
	Teacher(string name, string surname, int age, string gender, string faculty);
	Teacher(const Teacher &obj);
	virtual~Teacher();
	
private:
	string name;
	string surname;
	int age;
	string gender;
	string faculty;
	friend ostream& operator >> (istream& in, Teacher &teacer);
};

