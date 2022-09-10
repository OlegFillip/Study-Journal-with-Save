#pragma once
#define uint unsigned

union Journal {
	uint marks : 10;

	struct {
		uint Subject1 : 1;
		uint Subject2 : 1;
		uint Subject3 : 1;
		uint Subject4 : 1;
		uint Subject5 : 1;
		uint Subject6 : 1;
		uint Subject7 : 1;
		uint Subject8 : 1;
		uint Subject9 : 1;
		uint Subject10 : 1;
	};
};

struct Student {

	char* FirstName;
	char* MiddleName;
	char* LastName;
	Journal* journal;

};


void fillStudent(Student* student);

void showAverage(Student* student);

void generateStudents(Student** students);

void setMarksBySubject(Student** students, int studentsCount);
void changeNames(Student*** students, int quantity);
void deleteStudent(Student*** pstudents, int& studentsCount);


