#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{
public:
	//Constructors:
	NetworkStudent();
	NetworkStudent(string ID, string first, string last, string email, int age, int* daysArray, Degree program);

	//Methods that will overwrite virtual methods from superclass
	Degree GetDegreeProgram();
	void SetDegreeProgram(Degree program);
	void print();

	//Destructor:
	~NetworkStudent();


};