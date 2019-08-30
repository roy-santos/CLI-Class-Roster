#pragma once
#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::string;
using std::setw;


//Constructors:
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToComplete = new int[daysArraySize]; //Destructor needed
	//Initialize array elements to 0
	for (int i = 0; i < daysArraySize; ++i)
	{
		this->daysToComplete[i] = 0;
	}

}

Student::Student(string ID, string first, string last, string email, int age, int daysArray[], Degree program)
{
	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = age;
	this->daysToComplete = new int[daysArraySize]; //Destructor needed
	//Assign daysArray elements to daysToComplete data member
	for (int i = 0; i < daysArraySize; ++i)
	{
		this->daysToComplete[i] = daysArray[i];
	}
}

//Getters:
string Student::GetStudentID()
{
	return studentID;
}

string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}

string Student::GetEmailAddress()
{
	return emailAddress;
}

int Student::GetAge()
{
	return age;
}

int* Student::GetDaysToComplete()
{
	return daysToComplete;
}

//Setter:
void Student::SetStudentID(string ID)
{
	studentID = ID;
}

void Student::SetFirstName(string first)
{
	this->firstName = first;
}

void Student::SetLastName(string last)
{
	this->lastName = last;
}

void Student::SetEmailAddress(string email)
{
	this->emailAddress = email;
}

void Student::SetAge(int num)
{
	this->age = num;
}

void Student::SetDaysToComplete(int daysArray[])
{
	//Deletes deletes previous array before allocating memory with new.
	if (this->daysToComplete != nullptr)
	{
		delete[] this->daysToComplete;
		this->daysToComplete = nullptr;
	}
	this->daysToComplete = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; ++i)
	{
		this->daysToComplete[i] = daysArray[i];
	}

}

//Print method using accessors:
void Student::print()
{
	cout << left << setw(5) << GetStudentID();
	cout << left << setw(10) << GetFirstName();
	cout << left << setw(10) << GetLastName();
	cout << left << setw(25) << GetEmailAddress();
	cout << left << setw(6) << GetAge();
	cout << left << setw(4) << GetDaysToComplete()[0];
	cout << left << setw(4) << GetDaysToComplete()[1];
	cout << left << setw(12) << GetDaysToComplete()[2];
}

//Destructor
Student::~Student()
{
	if (daysToComplete != nullptr)
	{
		delete[] daysToComplete;
		daysToComplete = nullptr;
	}
}


