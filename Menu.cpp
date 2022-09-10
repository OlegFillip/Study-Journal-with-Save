#include <iostream>
#include "Student.h"
#include "Menu.h"
#include <fstream>
#define SUBJECTS 10


using namespace std;



void showMenu(Student*** pstudents, int& studentsCount) {

	bool noexit = true;

	do {


		cout << "Choose option" << endl;
		cout << "1- add student" << endl;
		cout << "2- set student marks" << endl;
		cout << "3- Print all students" << endl;
		cout << "4- Print student marks" << endl;
		cout << "5- change name" << endl;
		cout << "6- Show Journal" << endl;
		cout << "7- Set marks by Subject" << endl;
		cout << "0- Exit program" << endl;
		cout << "choose option form 0  to 7 :" << endl;

		bool set = true;
		int option = 0;
		do
		{
			cin >> option;
			if (option >= 0 && option <= 7) {
				break;
			}
			cout << "Enter rigt value: ";

		} while (true);

		switch (option)
		{
		case 1:
			addStudent(pstudents, studentsCount);
			break;
		case 2:

			setStudentMarks(pstudents, studentsCount);

			break;
		case 3:

			for (int i = 0; i < studentsCount; i++)
			{

				cout << "Student number : " << i << endl;

				printStudent((*pstudents)[i]);


			}


			break;
		case 4:
			printStudentMarks(pstudents, studentsCount);
			break;
		case 5:
             changeName(*pstudents, studentsCount);
			break;
			
		case 6:
			ReadFromFile(pstudents,studentsCount);
			break;		
		case 7:
			setMarksBySubject(*pstudents, studentsCount);
			break;
		case 0:
			SaveJournal(pstudents, studentsCount);
			noexit = false;
			break;
		default:
			break;
		}


	} while (noexit);

}


void setStudentMarks(Student*** students, int quantity) {

	int number = 0;
	cout << "Enter student number to set marks 1 to " << quantity << endl;
	cin >> number;

	Student* student = (*students)[(number - 1)];

	cout << endl << "Set marks for " << student->FirstName << " " << student->LastName << endl;


	Journal* newJournal = new Journal();

	for (int i = 0; i < SUBJECTS; i++)
	{
		bool pass = true;
		do {

			char answer;
			cout << "Enter passed mark for subject " << i + 1 << " (yes/no): ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y' || answer == 'n' || answer == 'N') {

				if (answer == 'N' || answer == 'n') {

					(newJournal->marks) &= ~(1 << i);

				}
				else {

					(newJournal->marks) |= (1 << i);

				}

				pass = false;

			}


		} while (pass);




	}

	Journal* old_journal = student->journal;
	delete old_journal;

	student->journal = newJournal;
}

void printStudent(Student* student) {

	cout << student->FirstName << " " << student->MiddleName << " " << student->LastName << endl;

	for (int i = 0; i < SUBJECTS; i++)
	{


		cout << "Subject " << i + 1 << ": ";//passs\notpass

		if (((student->journal->marks) >> i) & 1) {

			cout << "pass";
		}
		else {
			cout << "not pass";
		}
		cout << endl;
	}

}

void addStudent(Student*** students, int& studentCount) {

	Student* newStudent = new Student();

	fillStudent(newStudent);

	Student** newStudentsMas = new Student * [studentCount + 1];

	for (int i = 0; i < studentCount; i++)
	{
		newStudentsMas[i] = (*students)[i];
	}		

	studentCount++;

	newStudentsMas[studentCount-1] = newStudent;

	


	delete[] *students;

	*students = newStudentsMas;


}

void printStudentMarks(Student*** students, int quantity) {

	int number = 0;
	cout << "Enter student number to set marks 1 to " << quantity + 1 << endl;
	cin >> number;

	Student* student = (*students)[number - 1];

	for (int i = 0; i < SUBJECTS; i++)
	{


		cout << "Subject " << i + 1 << ": ";//passs\notpass

		if (((student->journal->marks) >> i) & 1) {

			cout << "pass";
		}
		else {
			cout << "not pass";
		}
		cout << endl;
	}
}

void SaveJournal(Student*** students, int& studentsCount) {
	ofstream fout;          // поток для записи
	fout.open("Journal.txt"); // окрываем файл для записи
	if (fout.is_open())
	{
		char c = studentsCount + 47;

		fout.write(&c,1);

		for (size_t i = 0; i < studentsCount; i++)
		{
			

			Student* student = (*students)[i];
			char* fname =	student->FirstName;
			fout.write(fname, 50);
			fout.write(student->MiddleName, 50);
			fout.write(student->LastName, 50);
			fout.write((char*)(student->journal), 10);
		}

	}
}

void ReadFromFile(Student*** students,int& studentsCount) {
	ifstream fin;
	fin.open("Journal.txt");

	if (!fin.is_open()) {

		cout << "Journal file not found - generating sample data";
		generateStudents(*students);
	}
	else {
		cout << "File opened";


		int quantity = 0;
		char c;
		fin.read(&c, 1);

		quantity = (int)c - 47;

		Student** new_st_arr = new Student * [quantity];

		delete[] *students;

		*students = new_st_arr;

		for (int i = 0; i < quantity; i++)
		{
			Student* student = new Student();
			Journal* newJournal = (Journal*)malloc(10);

			char* fname = new char[50];
			char* mname = new char[50];
			char* lname = new char[50];
			

			fin.read(fname, 50);
			fin.read(mname, 50);
			fin.read(lname, 50);
			fin.read((char*)newJournal, 10);

			student->FirstName = fname;
			student->MiddleName = mname;
			student->LastName = lname;
			student->journal = newJournal;

			(*students)[i] = student;

		}

		studentsCount = quantity;
	}

}
