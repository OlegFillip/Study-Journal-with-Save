#include <iostream>
#include "Student.h"
#define SUBJECTS 10

using namespace std;

void fillStudent(Student* student) {

	cout << "Enter First Name: ";
	char* name = new char[50];
	cin >> name;
	student->FirstName = name;


	cout << "Enter Middle Name: ";
	name = new char[50];
	cin >> name;
	student->MiddleName = name;

	cout << "Enter Last Name: ";
	name = new char[50];
	cin >> name;
	student->LastName = name;

	Journal* newJournal = new Journal();

	student->journal = newJournal;

}

void showAverage(Student* student) {
	float summ = 0;
	for (int i = 0; i < SUBJECTS; i++)
	{
		if (1 == ((student->journal->marks >> i) & 1))
			summ += 12;
		else
			summ += 1;

	}

	cout << "Average =  " << summ / SUBJECTS << endl;

}

void generateStudents(Student** students) {

	for (int i = 0; i < 10; i++)
	{
		char symbol[2] = " ";
		symbol[0] = 48 + i;


		char* first = new char[50];
		char* mid = new char[50];
		char* last = new char[50];

		strcpy_s(first, 50, "First");
		strcpy_s(mid, 50, "Mid");
		strcpy_s(last, 50, "Last");

		strcat_s(first, 50, symbol);
		strcat_s(mid, 50, symbol);
		strcat_s(last, 50, symbol);

		Student* student = new Student();
		Journal* journal = new Journal();
		journal->marks = 0;

		student->FirstName = first;
		student->MiddleName = mid;
		student->LastName = last;
		student->journal = journal;

		students[i] = student;
	}
}
