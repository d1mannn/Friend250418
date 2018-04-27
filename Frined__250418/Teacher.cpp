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

bool operator > (int str, Teacher obj)
{
	return(str > obj.age);
}


bool operator < (Teacher obj1, Teacher obj2)
{
	return (obj1.age > obj2.age);
}

bool operator < (int str, Teacher obj)
{
	return(str > obj.age);
}

istream& operator >> (istream& in, Teacher &teacher)
{
	string s;
	getline(in, s, '\n'); // сделали чтобы, первый \n после кол-во учителей не мешал для считывания
	getline(in, teacher.name, '\\');
	getline(in, teacher.surname, '\\');
	in >> teacher.age >> teacher.gender;
	getline(in, teacher.faculty, '\\');
	return in;
}


void printTeachers(Teacher *teacher, int countOfTeachers)
{
	for (int i = 0; i < countOfTeachers; i++)
	{	
		cout << teacher[i].name << "\t" << teacher[i].surname << "\t" <<
			teacher[i].age << "\t" << teacher[i].gender << "\t" << teacher[i].faculty << endl;
	}
}

void printTecaher(Teacher &teacher)
{
	cout << teacher.name << "\t" << teacher.surname << "\t" <<
		teacher.age << "\t" << teacher.gender << "\t" << teacher.faculty << endl;
}