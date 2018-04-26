#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include "Exam.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	Student *student;
	Teacher * teacher;
	Exam * exam;
	int n, n2;
	ifstream in_file("in.txt"); // открывает уже созданный файл
	ifstream in_teacher("teacher.txt");
	ofstream out_file("Exam.txt");
	//cout << "Enter number of students\n--->  ";
	in_file >> n; // считывает сколько студентов в файле, указали в in.txt - 2
	in_teacher >> n2;
	student = new Student[n]; // сработает конструктоп по умолчанию
	teacher = new Teacher[n2];
	exam = new Exam[n2 * n];
	for (int i = 0; i < n; i++)
	{	
		//cout << "Enter name, sturanme, age, gender, group" << endl;
		in_file >> student[i]; // friend istream
	}
	int i = 0;
	while (!in_teacher.eof())
	{
		in_teacher >> teacher[i++];
	}
	string subje;
	double grade;
	int k = 0;
	for (int i = 0; i < n2; i++)
	{	
		cout << "Enter subj for current teacher: ";
		cin >> subje;
		for (int j = 0; j < n; j++)
		{	
			cout << "Enter sgrade for current student: ";
			cin >> grade;
			//Exam e(subje, student[j].getSname(), teacher[i].getSname(), grade);
			exam[k++].create_exam(subje, student[j], teacher[i], grade);
		}
	}
	//for (int i = 0; i < n2; i++)
	//{
	//	in_teacher >> teacher[i]; //friend istream считываем с файла в класс
	//}
	cout <<"Students" << endl;
	printStudents(student, n); // проверяем дружественный метод
	cout << "\nTeachers" << endl;
	printTeachers(teacher, n2);
	cout << endl;
	PrintExams(exam, n2 * n);
	cout << endl;
	//cout << ("male" == student[0]) << endl;
	//cout << ("male" == student[1]) << endl;
	//cout << ("male" != student[0]) << endl;
	//cout << (student[0] < 18) << endl;
	//cout << (student[0] < 18) << endl;
	//cout <<( student[0] > student[1]) << endl;
	//cout << endl;
	//cout << "возраст больше 18?  "<<(18 > teacher[0]) << endl;
	////cout << "возраст больше 18?  " << (teacher[1] > 20) << endl;
	//cout << "возраст больше первого больше второго?  " << (teacher[1] > teacher[0]) << endl;
	//cout << "пол равен?  " << (teacher[0] == teacher[1]) << endl;
	int choice;
	cout << "Choose a task:\n----> ";
	cout << "1 - Print boys" << endl;
	cout << "2 - Print girls" << endl;
	cout << "0 - Exit" << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			for (int i = 0; i < n; i++)
			{
				if ("female" == student[i])
					printStudent(student);
			}
		} break;
	}

	in_file.close();
	in_teacher.close();
	delete[]student;
	delete[] teacher;
	delete[]exam;
	
	system("pause");
	return 0;
}