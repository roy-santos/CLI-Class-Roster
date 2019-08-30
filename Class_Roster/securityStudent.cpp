#pragma once
#include "securityStudent.h"
using std::cout;
using std::endl;

SecurityStudent::SecurityStudent() : Student()
{
	SetDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string ID, string first, string last, string email, int age, int* daysArray, Degree program)
	: Student(ID, first, last, email, age, daysArray, program)
{
	SetDegreeProgram(SECURITY);
}

//Getter for security student
Degree SecurityStudent::GetDegreeProgram()
{
	return SECURITY;
}

//Setter for security student
void SecurityStudent::SetDegreeProgram(Degree program)
{
	this->degreeProgram = SECURITY;
}

//Print
void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}
