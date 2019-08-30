#pragma once
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{
public:
	//Constructors:
	SoftwareStudent();
	SoftwareStudent(string ID, string first, string last, string email, int age, int* daysArray, Degree program);

	//Methods that will overwrite virtual methods from superclass
	Degree GetDegreeProgram();
	void SetDegreeProgram(Degree program);
	void print();

	//Destructor:
	~SoftwareStudent();


};