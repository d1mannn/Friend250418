#include "Library.h"
#include "Student.h"
#include "Teacher.h"
#include "Exam.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
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
		if (i == 0)
			subje = "Inform Technology";
		else if (i == 1)
			subje = "History";
		else
			subje = "Math";
		for (int j = 0; j < n; j++)
		{
			grade = 1 + rand() % 5;
			//Exam e(subje, student[j].getSname(), teacher[i].getSname(), grade);
			exam[k++].create_exam(subje, student[j], teacher[i], grade);
		}
	}
	for (int i = 0; i < n2; i++)
	{
		in_teacher >> teacher[i]; //friend istream считываем с файла в класс
	}



	
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
	do
	{
		cout << "Choose a task: " << endl;
		cout << "1 - Print boys" << endl;
		cout << "2 - Print girls" << endl;
		cout << "3 - Print students of the same group" << endl;
		cout << "4 - Print the youngest student" << endl;
		cout << "5 - Print the oldest student" << endl;
		cout << "6 - Infromation about teachers" << endl;
		cout << "7 - Print who got an excellent grade" << endl;
		cout << "8 - Print who got a bad grade" << endl;
		cout << "9 - Print all inform" << endl;
		cout << "0 - Exit" << endl;
		cout << "--->  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
				if ("male" == student[i])
					printStudent(student[i]);
			system("pause");
			system("cls");
		} break;

		case 2:
		{
			for (int i = 0; i < n; i++)
				if ("female" == student[i])
					printStudent(student[i]);
			system("pause");
			system("cls");
		} break;

		case 3:
		{
			int group;
			do
			{
				cout << "Enter group number (1-3)\n---> ";
				cin >> group;
			} while (group < 1 || group > 3);
			for (int i = 0; i < n; i++)
				if (group == student[i])
					printStudent(student[i]);
			system("pause");
			system("cls");
		} break;

		case 4:
		{
			int i = TheYoungestStudent(student, n);
			cout << "Самый младший студент - ";
			printStudent(student[i]);
			system("pause");
			system("cls");
		} break;

		case 5:
		{
			int i = TheOldestStudent(student, n);
			cout << "Самый старший студент - ";
			printStudent(student[i]);
			system("pause");
			system("cls");
		} break;

		case 6:
		{
			int i;
			cout << "Информацию о преподавателя какой кафедры хотите получить?" << endl;
			cout << "1 - Orientalistic" << endl;
			cout << "2 - Journalist" << endl;
			cout << "3 - Infrom Technology" << endl;
			do
			{
				cout << "--->  ";
				cin >> i;
			} while (i < 1 || i > 3);
			switch (i)
			{
			case 1: printTecaher(teacher[i - 1]);
				break;
			case 2: printTecaher(teacher[i - 1]);
				break;
			case 3: printTecaher(teacher[i - 1]);
				break;
			}
			system("pause");
			system("cls");
		} break;

		case 7:
		{
			for (int i = 0; i < n * n2; i++)
			{
				if (exam[i] == 5)
					PrintExam(exam[i]);
			}
			system("pause");
			system("cls");
		} break;

		case 8:
		{
			for (int i = 0; i < n * n2; i++)
			{
				if (exam[i] <= 2)
					PrintExam(exam[i]);
			}
			system("pause");
			system("cls");
		} break;

		case 9:
		{
			cout << "Students" << endl;
			printStudents(student, n); // проверяем дружественный метод
			cout << "\nTeachers" << endl;
			printTeachers(teacher, n2);
			cout << endl;
			PrintExams(exam, n2 * n);
			cout << endl;
			system("pause");
			system("cls");
		} break;
		}
	} while (choice != 0);
	
	in_file.close();
	in_teacher.close();
	delete[]student;
	delete[] teacher;
	delete[]exam;

	system("pause");
	return 0;
}