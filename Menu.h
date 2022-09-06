#pragma once
#include "Student.h"

void showMenu(Student*** students, int& studentsCount);
void addStudent(Student*** students, int& studentCount);
void printStudent(Student* student);
void setStudentMarks(Student*** students, int quantity);
void printStudentMarks(Student*** students, int quantity);
void SaveJournal(Student*** students, int& studentsCount);
void ReadFromFile(Student*** students,int& studentsCount);