#include "Exam.h"



Exam::Exam(string sub, string teach, string stud, double grade)
{
	this->subject = sub;
	this->student_sname = stud;
	this->teacher_sname = teach;
	this->grade = grade;
}

Exam::Exam(const Exam &obj)
{
	this->subject = obj.subject;
	this->student_sname = obj.student_sname;
	this->teacher_sname = obj.teacher_sname;
	this->grade = obj.grade;
}

Exam::Exam(string subject, Student sobj, Teacher tobj, double grade)
{
	this->subject = subject;
	this->student_sname = sobj.surname;
	this->teacher_sname = tobj.surname;
	this->grade = grade;
}
void Exam::create_exam(string subject, Student sobj, Teacher tobj, double grade)
{	
	this->subject = subject;//чтобы были доступны свойства необходимо добавить в друзья в классах студ и тичер
	this->student_sname = sobj.surname;
	this->teacher_sname = tobj.surname;
	this->grade = grade;
}

void PrintExams(Exam * exam, int countOfEx)
{
	for (int i = 0; i < countOfEx; i++)
	{
		cout <<"Teacher: "  << exam[i].teacher_sname << "\tSubject: " << exam[i].subject
			<< "\tStudent: " << exam[i].student_sname << "\tResult: " << exam[i].grade << endl;
	}
}

Exam::~Exam()
{
}
