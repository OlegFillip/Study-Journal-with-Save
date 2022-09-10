#include <iostream>
#include "Student.h"
#include "Menu.h"

using namespace std;
int main()
{

	int studentsCount = 10;
	Student** students = new Student * [studentsCount];

	ReadFromFile(&students, studentsCount);

	showMenu(&students, studentsCount);
	
	//End of a programm

}
