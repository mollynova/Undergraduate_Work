#include<iostream>

#ifndef STUDENT_H
#define STUDENT_H

class Student{

    public:

    Student();
    Student(char* name, char* major, float GPA);
    ~Student();
    Student& operator=(Student& student);

    char* getName() { return name; }
    char* getMajor() { return major; }
    float getGPA() { return GPA; }

    private:
        char* name;
        char* major;
        float GPA;

};

#endif
