#pragma once
#include "degree.h"
#include <string>
using std::string;

class Student
{
public:
	//Constant array size for days to complete
	const static int daysArraySize = 3;

	//Constructors:
	Student(); //Default constructor with no parameters
	Student(string ID, string first, string last, string email, int age, int daysArray[], Degree program);

	//Getters:
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int    GetAge();
	int* GetDaysToComplete();
	virtual Degree GetDegreeProgram() = 0;

	//Setters:
	void SetStudentID(string ID);
	void SetFirstName(string first);
	void SetLastName(string last);
	void SetEmailAddress(string email);
	void SetAge(int num);
	void SetDaysToComplete(int daysArray[]); //May have to fix pass by ref or pass by val?
	void SetDegreeProgram(Degree type);

	//Print:
	virtual void print() = 0;

	//Destructor:
	~Student();

protected: //allows subclasses to access these data members
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int    age;
	int* daysToComplete; //Pointer to an array
	Degree degreeProgram;

};


