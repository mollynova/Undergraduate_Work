#include "functions.h"
#include <iostream>

using namespace std;

void getValues(int& x,int& y) {
    cout << "Enter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y;
}


int main() {

  int choice;
  bool done = false;
  int x,y;

  cout << "Welcome to the math functionator!" << endl << endl;

  do {
    cout << "1) GCD" << endl;
    cout << "2) LCM" << endl;
    cout << "3) average" << endl;
    cout << "0) quit" << endl;
    cout << "Enter choice: ";

    cin >> choice;

    if (choice != 0) {
	getValues(x,y);
    }
    
    switch (choice) {
	case 1:

	    doGCD(x,y);
	    break;
	case 2:
	    doLCM(x,y);
	    break;
	case 3:
	    doAverage(x,y);
	    break;
	case 0:
	    done = true;
    }
  } while (!done);
  
  cout << "Bye" << endl;

  return(0);
}
