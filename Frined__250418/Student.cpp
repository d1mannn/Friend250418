#include "Student.h"
#include "Library.h"


Student::Student()
{	
	name = "";
	surname = "";
	age = 0;
	gender = "";
	group = 0;
}


Student::~Student()
{
}

Student::Student(string name, string surname, int age, int group, string gender)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->group = group;
	this->gender = gender;
}

Student::Student(const Student&obj)
{
	this->age = obj.age;
	this->name = obj.name;
	this->surname = obj.surname;
	this->group = obj.group;
	this->gender = obj.gender;
}

bool Student::operator<(int age)
{
	return this->age < age;
}


void printStudents(Student * students, int countOfStudents)
{	
	//(gen = (students[i].gender == male ? "male" : "female"))
	string gen;
	for (int i = 0; i < countOfStudents; i++)
	{
		cout << students[i].name << "\t" << students[i].surname << "\t" << students[i].age << "\t" << students[i].gender << "\t" << students[i].group << endl;
	}
	cout << endl;
}

istream& operator >> (istream& in, Student &student)
{	
	string s;
	getline(in, s, '\n');
	getline(in, student.name, '\\'); // с какого потока считывать, куда, и до куда
	getline(in, student.surname, '\\');
	in >> student.age >> student.gender >> student.group; // считывает с файла
	//getline(in, student.group, '\n');
	return in; // чтоб вернул измененный поток ввода, где мы собрали все данные о студенте
}

bool operator==(string gender, Student obj)
{
	return (gender == obj.gender);
}

bool operator !=(string gender, Student obj)
{
	return (gender == obj.gender);
}

bool operator >(Student obj1, Student obj2)
{
	return obj1.age > obj2.age;
}