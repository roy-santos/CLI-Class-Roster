#pragma once
#include <iomanip>
#include "roster.h"
#include "student.h"
using std::cout;
using std::endl;
using std::cerr;
using std::setw;
using std::left;
using std::setfill;

//Constructors:
Roster::Roster()
{
	this->lastIndex = -1;
	this->capacity = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->lastIndex = -1;
	this->capacity = capacity;
	this->classRosterArray = new Student * [capacity];
}

//Pre-processing string input to separate into parameters for add method:
void Roster::ParseThenAdd(string row)
{
	//Determine if roster has reached capacity before proceeding:
	if (lastIndex < capacity)
	{
		++lastIndex;

		Degree degreeType;
		//Determine degree program and create new student for that program:
		if (row.substr(row.length() - 8, 8) == "SECURITY")
		{
			degreeType = SECURITY;
		}
		else if (row.substr(row.length() - 7, 7) == "NETWORK")
		{
			degreeType = NETWORK;
		}
		else if (row.substr(row.length() - 8, 8) == "SOFTWARE")
		{
			degreeType = SOFTWARE;
		}
		else
		{
			cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
			exit(-1);
		}
		//parsing through student string delimitting on the comma:

		/*Get comma position then the string up to that comma knowing that strings are
		ordered ID, first, last, email, age, day1, day2, day3, degreeType
		comma position is incrememented to next comma in row to get next piece of data*/
		int rhs = row.find(",");
		string ID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string first = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string last = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		//Type conversion from string to int:
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day3 = stoi(row.substr(lhs, rhs - lhs));

		//Call add method:
		Add(ID, first, last, email, age, day1, day2, day3, degreeType);
	}
	else
	{
		cerr << "ERROR! ROSTER HAS EXCEEDED MAXIMUM CAPACITY!" << endl << "EXITING NOW!";
		exit(-1);
	}
}

//Add students from student data to the roster:
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program)
{
	//Create an array using the daysInCourse arguments:
	int daysArray[Student::daysArraySize];
	daysArray[0] = daysInCourse1;
	daysArray[1] = daysInCourse2;
	daysArray[2] = daysInCourse3;

	//Add student based on degree program:
	if (program == SECURITY)
	{
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysArray, program);
	}
	else if (program == NETWORK)
	{
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysArray, program);
	}
	else
	{
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysArray, program);
	}
}

//Remove student from the roster:
bool Roster::Remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->GetStudentID() == ID) //Evauluates to true if student ID is in the class roster.
		{
			found = true;
			delete this->classRosterArray[i]; //Deletes the student from the roster
			this->classRosterArray[i] = this->classRosterArray[lastIndex]; //Replaces removed student with last student in the roster
			--lastIndex;
		}
	}
	//Prints error message if student ID cannot be found in the roster:
	if (!found)
	{
		cout << "Student ID not found!" << endl;
	}
	return found;
}

//Accesses students in the class roster array:
Student* Roster::GetStudentAt(int index)
{
	return classRosterArray[index];
}

//Print methods:
void Roster::PrintAll()
{
	cout << left << setw(5) << "ID";
	cout << left << setw(10) << "First";
	cout << left << setw(10) << "Last";
	cout << left << setw(25) << "Email";
	cout << left << setw(6) << "Age";
	cout << left << setw(20) << "Days In Course";
	cout << left << "Degree" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i <= this->lastIndex; ++i)
	{
		(this->classRosterArray)[i]->print();
	}
	cout << endl;
}

void Roster::PrintDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->GetStudentID() == studentID)
		{
			found = true;
			int* days = classRosterArray[i]->GetDaysToComplete();
			cout << "Average days to complete 3 courses for student ID " << studentID << " is "
				<< (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
	if (!found)
	{
		cout << "Student ID " << studentID << " not found!" << endl;
	}
}

void Roster::PrintInvalidEmails()
{
	bool anyInvalid = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		//finds presence of ' ', absense of '@' or '.' to determine validity
		if (classRosterArray[i]->GetEmailAddress().find(' ') != string::npos ||
			classRosterArray[i]->GetEmailAddress().find('@') == string::npos ||
			classRosterArray[i]->GetEmailAddress().find('.') == string::npos)
		{
			anyInvalid = true;
			cout << "Student ID " << classRosterArray[i]->GetStudentID() << ": ";
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
	if (!anyInvalid)
	{
		cout << "No invalid emails." << endl;
	}
}

void Roster::PrintByDegreeProgram(Degree program)
{
	bool validProgram = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (classRosterArray[i]->GetDegreeProgram() == program)
		{
			validProgram = true;
			classRosterArray[i]->print();
		}
	}
	if (!validProgram)
	{
		cout << "NONE!" << endl;
	}
}

//Destructor
Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		delete this->classRosterArray[i]; //Deletes each object
	}
	delete classRosterArray; //Deletes array of pointers to the objects

	cout << "Destructor called!" << endl;
}

/* **MAIN FUNCTION STARTS BELOW** */
/* **MAIN FUNCTION STARTS BELOW** */
/* **MAIN FUNCTION STARTS BELOW** */

int main()
{
	cout << endl;
	cout << "*************************************************************************************" << endl;
	cout << "Name: Roy Santos" << endl;
	cout << "Student ID: #001186453" << endl;
	cout << "Class: C867 - Scripting and Programming Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "*************************************************************************************" << endl;
	cout << endl;

	int numStudents = 5;

	//Input data for the roster. Comma-delimited strings:
	string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Roy,Santos,rsant67@wgu.edu,30,24,22,18,SOFTWARE"
	};

	//Create instance of the roster:
	Roster* classRoster = new Roster(numStudents);

	cout << "Parsing data and adding students:" << endl;

	//Add each student data to the roster:
	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->ParseThenAdd(studentData[i]);
	}

	cout << "DONE." << endl << endl;

	//Prints all students in the roster:
	cout << "Displaying student roster:" << endl;
	classRoster->PrintAll();

	//Prints invalid email adderesses (has "@" and "." symbols and no " " spaces):
	cout << "Printing invalid email addresses:" << endl;
	classRoster->PrintInvalidEmails();

	cout << endl;

	//Prints average number of days in 3 courses (loops through roster):
	cout << "Printing average number of days in 3 courses:" << endl;
	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->PrintDaysInCourse(classRoster->GetStudentAt(i)->GetStudentID());
	}

	cout << endl;


	//Prints out software students:
	Degree degreeProgram = SOFTWARE;

	cout << "Printing SOFTWARE students:" << endl;

	for (int i = 0; i <= numStudents; ++i)
	{
		if (classRoster->GetStudentAt(i)->GetDegreeProgram() == degreeProgram)
		{
			cout << left << setw(5) << "ID";
			cout << left << setw(10) << "First";
			cout << left << setw(10) << "Last";
			cout << left << setw(25) << "Email";
			cout << left << setw(6) << "Age";
			cout << left << setw(20) << "Days In Course";
			cout << left << "Degree" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			break;
		}

	}

	classRoster->PrintByDegreeProgram(degreeProgram);

	cout << endl;

	//Removes student with ID A3 (prints roster to show A3 was removed):
	cout << "Removing A3:" << endl;
	if (classRoster->Remove("A3"))
	{
		classRoster->PrintAll();
		--numStudents;
	}

	cout << endl;

	//Removes student with ID A3 again (expected error message):
	cout << "Removing A3:" << endl;
	if (classRoster->Remove("A3"))
	{
		classRoster->PrintAll();
		--numStudents;
	}

	cout << endl;

	//Calling destructor:
	cout << "Calling destructor:" << endl;
	classRoster->~Roster();

	return 0;
};