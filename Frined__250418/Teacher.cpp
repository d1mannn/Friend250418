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

bool operator == (Teacher obj1, Teacher obj2)
{
	return (obj1.gender == obj2.gender);
}

bool operator == (string & str, Teacher obj)
{
	return(str == obj.gender);
}

bool operator != (Teacher obj1, Teacher obj2)
{
	return (obj1.gender != obj2.gender);
}

bool operator != (string & str, Teacher obj)
{
	return(str != obj.gender);
}

bool operator > (Teacher obj1, Teacher obj2)
{
	return (obj1.age > obj2.age);
}

bool operator > (int & str, Teacher obj)
{
	return(str > obj.age);
}

bool operator < (Teacher obj1, Teacher obj2)
{
	return (obj1.age > obj2.age);
}

bool operator < (int & str, Teacher obj)
{
	return(str > obj.age);
}