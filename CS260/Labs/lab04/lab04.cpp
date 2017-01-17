#include <iostream>
using namespace std;


int main(){

// Declare variables
int numOfValues = 0;
int value = 0;

// get data
cout << "How many values will you enter: ";
cin >> numOfValues;
cout << endl;

// safeguarding against bad data
BadDataTest:if(numOfValues > 20){
	cout << "You have exceeded the maximum of 20. Please reenter the number of values you will enter: ";
	cin >> numOfValues;
	goto BadDataTest;
}

// make an array of integers the size of the number of values to store the values in
// loop through the right number of times and put the right value in the right spot
int data[numOfValues];
for(int i = 0; i < numOfValues; i++){
	cout << "Enter a number between 0 and 10 (inclusive):";
	cin >>  value;
	cout << endl;

	BadDataTestTwo:if(value < 0){
		cout << "Invalid value. Try Again." << endl;
		cin >> value;
		goto BadDataTestTwo;
	}

	data[i] = value;
	
}

int starArray[10][numOfValues];

// now we store each value in a 2d array
for(int j = 0; j < numOfValues; j++){
	
	int numOfStars = data[j];
	int numOfBlanks = 10 - data[j];
	
	// instead of a char * array, i made an int array
	// I'm going to store 0s where I want to print blanks
	// and I'm going to store 1s where I want to print *s
	// then I can say something like if starArray[0][9]==0 cout << " "
	// it just seems cleaner to me than storing blank spaces and stars
	for(int k = 0; k < numOfBlanks; k++){
		starArray[k][j] = 0;
	}

	for(int l = 0; l < numOfStars; l++){
		starArray[10-numOfStars+l][j] = 1;
	}
}	

// now we print the array

for(int m = 0; m < 10; m++){
	for(int n = 0; n < numOfValues; n++){
		if(starArray[m][n] == 0){	
			cout << " ";
		}
		if(starArray[m][n] == 1){
			cout << "*";
		}
	}
	cout << endl;
}

return(0);
}
