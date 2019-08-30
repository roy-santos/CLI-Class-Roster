#pragma once
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster
{
public:
	//Constructors:
	Roster(); //Default constructors
	Roster(int capacity); //Constructor that sets the max size of the roster

	//Pre-processing string input to separate into parameters for add method:
	void ParseThenAdd(string row);

	//Mutates class roster array:
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
	bool Remove(string studentID);

	//Accesses student in the class roster array:
	Student* GetStudentAt(int index);

	//Print methods:
	void PrintAll();
	void PrintDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(Degree program);

	//Destructor:
	~Roster();

	//Protected:
	Student** classRosterArray; //Array of pointers to students.
	int lastIndex; // Keeps track of students in the roster
	int capacity; //Max size of roster
};