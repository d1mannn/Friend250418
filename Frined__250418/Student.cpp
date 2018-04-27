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


int Student::TheYoungestStudent(int &age)
{
	if (this->age < age)
		return 1;
	else
		return 0;
}


void printStudents(Student * students, int countOfStudents)
{	
	//(gen = (students[i].gender == male ? "male" : "female"))
	for (int i = 0; i < countOfStudents; i++)
	{
		cout << students[i].name << "\t" << students[i].surname << "\t" << students[i].age << "\t" << students[i].gender << "\t" << students[i].group << endl;
	}
	cout << endl;
}

void printStudent(Student &students)
{
	cout << students.name << "\t" << students.surname << "\t" << students.age << "\t" << students.gender << "\t" << students.group << endl;
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

bool operator==(int group, Student obj)
{
	return (group == obj.group);
}

int TheYoungestStudent(Student* obj, int &length)
{	
	int minAge = obj[0].age;
	int index;
	for (int i = 1; i < length; i++)
	{
		if (obj[i].age < minAge)
		{
			minAge = obj[i].age;
			index = i;
		}
	}
	return index;
}

int TheOldestStudent(Student* obj, int &length)
{
	int maxAge = obj[0].age;
	int index;
	for (int i = 1; i < length; i++)
	{
		if (obj[i].age > maxAge)
		{
			maxAge = obj[i].age;
			index = i;
		}
	}
	return index;
}

bool operator == (Student obj, int grade)
{
	return obj.age > grade;
}