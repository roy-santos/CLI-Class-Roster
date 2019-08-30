#pragma once
#include "networkStudent.h"
using std::cout;
using std::endl;

NetworkStudent::NetworkStudent() : Student()
{
	SetDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string ID, string first, string last, string email, int age, int* daysArray, Degree program)
	: Student(ID, first, last, email, age, daysArray, program)
{
	SetDegreeProgram(NETWORK);
}

//Getter for network student
Degree NetworkStudent::GetDegreeProgram()
{
	return NETWORK;
}

//Setter for netowrk student
void NetworkStudent::SetDegreeProgram(Degree program)
{
	this->degreeProgram = NETWORK;
}

//Print
void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}
