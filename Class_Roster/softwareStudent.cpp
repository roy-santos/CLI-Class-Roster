#pragma once
#include "softwareStudent.h"
using std::cout;
using std::endl;

SoftwareStudent::SoftwareStudent() : Student()
{
	SetDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string ID, string first, string last, string email, int age, int* daysArray, Degree program)
	: Student(ID, first, last, email, age, daysArray, program)
{
	SetDegreeProgram(SOFTWARE);
}

//Getter for software student
Degree SoftwareStudent::GetDegreeProgram()
{
	return SOFTWARE;
}

//Setter for software student
void SoftwareStudent::SetDegreeProgram(Degree program)
{
	this->degreeProgram = SOFTWARE;
}

//Print
void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}
