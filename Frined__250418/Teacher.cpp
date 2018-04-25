#include "Teacher.h"
//#include <iostream>
//using namespace std;
//#include "Library.h"


Teacher::Teacher()
{
	name = "";
	surname = "";
	age = 0;
	gender = "";
	faculty = "";
}

Teacher::~Teacher()
{
}

Teacher::Teacher(string name, string surname, int age, string gender, string faculty)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->gender = gender;
	this->faculty = faculty;
}

Teacher::Teacher(const Teacher &obj)
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->age = obj.age;
	this->gender = obj.gender;
	this->faculty = obj.faculty;
	
}


