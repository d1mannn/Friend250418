#include "Library.h"
#include "Student.h"



int main()
{
	setlocale(LC_ALL, "Rus");
	Student *student;
	int n;
	ifstream in_file("in.txt");
	//cout << "Enter number of students\n--->  ";
	in_file >> n; // считывает сколько студентов в файле, указали в in.txt - 2
	student = new Student[n]; // сработает конструктоп по умолчанию
	for (int i = 0; i < n; i++)
	{	
		//cout << "Enter name, sturanme, age, gender, group" << endl;
		in_file >> student[i]; // friend istream
	}

	printStudents(student, n); // проверяем дружественный метод
	cout << ("male" == student[0]) << endl;
	cout << ("male" == student[1]) << endl;
	cout << ("male" != student[0]) << endl;
	cout << (student[0] < 18) << endl;
	cout << (student[0] < 18) << endl;
	cout <<( student[0] > student[1]) << endl;
	delete[]student;
	system("pause");
	return 0;
}