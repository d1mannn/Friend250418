#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "Library.h"
#include "Exam.h"

class Student
{
public:
	Student();
	Student(string name, string surname, int age, int group, string gender);
	Student(const Student&obj);

	virtual~Student(); //virtual - ��������� ����� �������, ������� ����� ����������� � �������� �������
	bool operator< (int age);
	string getSname() { return surname; }
	string getGender() { return gender; }
	int getGroup() { return group; }
	int TheYoungestStudent(int &age);
private:
	string name;
	string surname;
	int age;
	string gender;
	int group;
	friend void printStudents(Student * students, int countOfStudents);
	friend void printStudent(Student &students);
	friend istream& operator >> (istream& in, Student &student); //istream - �������� ����� �� ����� � ���������
	friend bool operator==(string gender, Student obj); //��������� gender � ���������� � obj
	friend bool operator==(int group, Student obj);
	friend bool operator == (Student obj, int grade);
	friend bool operator !=(string gender, Student obj);
	friend bool operator>(Student obj1, Student obj2);
	friend int TheYoungestStudent(Student* obj, int &length);
	friend int TheOldestStudent(Student* obj, int &length);
	friend class Exam;
};

#endif // !_STUDENT_H_
