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

void setMarksBySubject(Student** students, int studentsCount) {

	int subject;
	bool selected_right = false;
	do
	{
		cout << "Enter subject number 1 - " << SUBJECTS << ": ";
		cin >> subject;

		if (subject > 0 && subject < SUBJECTS + 1) {

			selected_right = true;
		}

	} while (!selected_right);

	cout << " Set marks for subject " << subject;

	for (int i = 0; i < studentsCount; i++)
	{
		bool mark;

		cout <<endl <<"Mark for " << students[i]->FirstName<<" "<< students[i]->LastName << " y/n :";

		char select;
		bool selected_right = false;
		do
		{
			
			cin >> select;

			if (select == 'y' || select == 'Y' || select == 'n' || select == 'N') {

				selected_right = true;
				
			}

		} while (!selected_right);

		switch (subject)
		{

		case 1:
			students[i]->journal->Subject1 = (select == 'y' || select == 'Y');
			break;			
		case 2:
			students[i]->journal->Subject2 = (select == 'y' || select == 'Y');
			break;			
		case 3:
			students[i]->journal->Subject3 = (select == 'y' || select == 'Y');
			break;			
		case 4:
			students[i]->journal->Subject4 = (select == 'y' || select == 'Y');
			break;			
		case 5:
			students[i]->journal->Subject5 = (select == 'y' || select == 'Y');
			break;			
		case 6:
			students[i]->journal->Subject6 = (select == 'y' || select == 'Y');
			break;			
		case 7:
			students[i]->journal->Subject7 = (select == 'y' || select == 'Y');
			break;			
		case 8:
			students[i]->journal->Subject8 = (select == 'y' || select == 'Y');
			break;			
		case 9:
			students[i]->journal->Subject9 = (select == 'y' || select == 'Y');
			break;			
		case 10:
			students[i]->journal->Subject10 = (select == 'y' || select == 'Y');
			break;
		default:
			break;
		}
	}

}
void changeName(Student** students, int studentsCount)

{

	int number_student;
	cout << "Enter student number to change name: " << endl;
	cin >> number_student;

	
		if (number_student >= 0 && number_student <= studentsCount) 
		{
			for (int i = 0; i < studentsCount; i++)
			{
				char* first = new char[50];
				char* mid = new char[50];
				char* last = new char[50];
				if (i == number_student)
				{
					cout << "Enter FirstName: " << endl;
					cin >> first;
					students[i]->FirstName = first;
					cout << "Enter MiddleName: " << endl;
					cin >> mid;
					students[i]->MiddleName = mid;
					cout << "Enter LastName: " << endl;
					cin >> last;
					students[i]->LastName = last;


				}
			}
		}
		else {
			cout << "This student is not on the list!!!" << endl;
		}
		


	
}