#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

float averageGPA(int numOfStudent, Student* table)
{
	float totalGPA = 0;

	for(int i = 0; i < numOfStudent; i++){
		totalGPA += table[i].getGPA();
	}
	
	return (totalGPA/numOfStudent);
}

float averageGPAByMajor(int numMajors, char** majors, Student * table, int numStudents)
{	
	cout << "    Average GPA per major: " << endl;

	// to loop thru majors array
	for(int i = 0; i < numMajors; i++){
		// to loop through the table to check for ones of that major
		cout << "        major " << (i + 1) << "(" << majors[i] << "): ";
		float students = 0;
		float cumulative = 0;

		for(int j = 0; j < numStudents; j++){

			if(strcmp(majors[i], table[j].getMajor()) == 0){
				students++;
				cumulative += table[j].getGPA();
			}
		}
		// setprecision and static_cast didn't work for me but printf did
		printf("%.1f", (cumulative/students));
		cout << endl;
	}

	return 0;
}

bool newMajor(char* major, Student* table, int currAdded)
{
	if(currAdded == 1){
		return true;
	}

	for(int i = 0; i < currAdded - 1; i++){
		if(strcmp(table[i].getMajor(), major) == 0){
			return false;
		}
	}
	
	return true;
}

void printDiagnostics(int numOfStudents, Student * table, int numMajors, char** majors)
{
	cout << endl << "--Now printing student diagnostics--" << endl << endl;
        cout << "    Total number of students: " << numOfStudents << endl;
        cout << "    Average GPA for all students: ";
	printf("%.1f", averageGPA(numOfStudents, table));
        cout << endl << "    Number of different majors: " << numMajors << endl;
        averageGPAByMajor(numMajors, majors, table, numOfStudents);
}

int main()
{
	
	// Declare variables
	int numMajors = 0;			// keeps track of the total number of Majors
	int currAdded = 0;			// keeps track of how many students have been added THUS FAR
	const int MAX_MAJORS = 100;		// max number of majors allowed
	const int MAX_LENGTH = 25;		// max length of character array
	const int TABLE_SIZE = 100;		// max table size
        int numStudents = 0;			// total number of students being added
        char* name = new char[MAX_LENGTH];	// cin>>name
        char* major = new char[MAX_LENGTH];     // cin>>major
        float GPA = 0;				// cin>>gpa

	//Get Data
        cout << "--Student Database Data Entry--" << endl << endl;
        cout << "Enter the number of students in registry: ";
        cin >> numStudents;

        cout << endl << "Enter data for each student: " << endl;

        Student table[TABLE_SIZE];
	char* majors[MAX_MAJORS];

        for(int i = 0; i < numStudents; i++){

		cout << "    Student " << (i+1) << " : " << endl;
		cout << "        Last Name: ";
		
		// need to use getline to cin multiple words, so using
		// cin.ignore() to eat the trailing \n from cin>>numStudents
		
		cin.ignore();
		cin.getline(name, MAX_LENGTH);
		cout << "        Major: ";
		cin.getline(major, MAX_LENGTH);
		cout << "        GPA: ";
		cin >> GPA;
		
		Student* newStudent = new Student(name, major, GPA);
		
        	table[i] = *newStudent;

		currAdded++;
		// Check if major already exists, if not add to array of majors
			
		if(newMajor(table[i].getMajor(), table, currAdded)){
			// if newMajor is true, increment numMajors
			numMajors++;
			// add new major to array of majors
			majors[numMajors - 1] = table[i].getMajor();
		}
        }
	
	printDiagnostics(numStudents, table, numMajors, majors);

	getchar();
	getchar();

        return(0);
}
