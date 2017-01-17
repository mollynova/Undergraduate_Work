#include<iostream>
#include "functions.h"
using namespace std;

void doAverage(int x, int y) {

	int sum = x + y;
	int average = sum / 2;

	cout << "Average of " << x << " and " << y << " is " << average << endl;
}

void doGCD(int x, int y){
		
	int numOne = x;
	int numTwo = y;

	while(numOne != 0 || numTwo != 0){
	    while(numOne != numTwo){
		while(numOne > numTwo){
		    numOne = numOne - numTwo;
		}
		while(numTwo > numOne){
		    numTwo = numTwo - numOne;
		}
	    }
     	    printGCD(x, y, numOne);
	    break;
	}
}

void doLCM(int x, int y){

	int noOne = x;
	int noTwo = y;
	int product  = x * y;
	int LCM = 0;

	while(noOne != 0 || noTwo != 0){
	    while(noOne != noTwo){
		while(noOne > noTwo){
		    noOne = noOne - noTwo;
		}
	        while(noTwo > noOne){
		    noTwo = noTwo - noOne;
		}
	    }
  	    LCM = product / noOne;
	    cout << "The LCM of " << x << " and " << y << " is " << LCM << endl;
	    break;
	}

}

void printGCD(int x, int y, int GCD){

	if(x == 0 || y == 0)
	    cout << "The GCD of " << x << " and " << y << " is 1." << endl;
	else
	    cout << "The GCD of " << x << " and " << y << " is " << GCD << endl;

}
