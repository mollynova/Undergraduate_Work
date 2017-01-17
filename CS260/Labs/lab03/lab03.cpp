#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
// Declare variables
int cinStartBalance = 0;
int cinInterestRate = 0;
int cinNoYears = 0;
double endBalance = 0;
double StartBalance = 0;
double InterestRate = 0;

// Get data
cout << "Enter starting balance: ";
cin >>  cinStartBalance;
cout << endl << "Enter interest rate: ";
cin >> cinInterestRate;
cout << endl << "Enter number of years: ";
cin >> cinNoYears;
cout << endl;

// convert?
StartBalance = static_cast<double>(cinStartBalance);
InterestRate = static_cast<double>(cinInterestRate);

// Do computations and output info
for(int i = 0; i < cinNoYears; i++){
	if (i == 0){
		endBalance = (StartBalance)  * (1+(InterestRate/100));
		cout <<  "Year " << (i+1) << " $";
		cout << setprecision(16) << endBalance << endl;
	} else {    
		endBalance  = endBalance * (1+(InterestRate/100));
    		cout << "Year " << (i+1) << " $";
		cout << setprecision(16) << endBalance << endl;
	}
}


//for (int j = 0; j < cinNoYears; j++){
    
//}
return (0);
}
