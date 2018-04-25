#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "Library.h"


class Student
{
public:
	Student();
	Student(string name, string surname, int age, int group, string gender);
	Student(const Student&obj);
	virtual~Student(); //virtual - ��������� ����� �������, ������� ����� ����������� � �������� �������
	bool operator< (int age);
private:
	string name;
	string surname;
	int age;
	string gender;
	int group;
	friend void printStudents(Student * students, int countOfStudents);
	friend istream& operator >> (istream& in, Student &student); //istream - �������� ����� �� ����� � ���������
	friend bool operator==(string gender, Student obj); //��������� gender � ���������� � obj
	friend bool operator !=(string gender, Student obj);
	friend bool operator>(Student obj1, Student obj2);
};

#endif // !_STUDENT_H_
