#include<iostream>
#include<cstring>
#include "student.h"

using namespace std;

Student::Student() :
    name(NULL),
    major(NULL),
    GPA(0)
{
}

Student::Student(char* name, char* major, float GPA) 
{
    this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
    this->major = new char[strlen(major) + 1];
	strcpy(this->major, major);
    this->GPA = GPA;
}

Student::~Student()
{
    if(name)
        delete [] name;
		
	if(major)
		delete [] major;
}

Student& Student::operator=(Student& student)
{
    this->name = student.name;
    this->major = student.major;
    this->GPA = student.GPA;
    return *this;
}
