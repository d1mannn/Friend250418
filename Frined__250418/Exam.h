#pragma once
#include "Library.h"
#include "Student.h"
#include "Teacher.h"

class Student;
class Teacher;
//обязательно указываем те классы, которые будем использовать. либо добавляем в library.h
class Exam
{
public:
	Exam() = default;
	Exam(string, string, string, double);
	Exam(string subject, Student sobj, Teacher tobj, double grade);
	void create_exam(string subject, Student sobj, Teacher tobj, double grade);
	
	Exam(const Exam &obj);

	~Exam();
private:
	string subject;
	string teacher_sname;
	string student_sname;
	double grade;
	friend void PrintExams(Exam *exam, int countOfEx);
};

