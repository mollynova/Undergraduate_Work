#include<iostream>
#include<fstream>
#include<set>
#include<iterator>
#include<cstring>

using namespace std;

int main(int argc, char* argv[])
{
   
   // Declare variables
  
   set<string> mySet;
   set<string>::iterator it;
   string tmpWord;
   string pathName;

   // Prompt user for file pathname
   cout << "\n\nPlease enter the full pathname of the file you wish to read in: ";
   cin >> pathName;
   
   ifstream myFile (pathName);
   if(myFile.is_open()){
      while(myFile >> tmpWord)
      {
        string tmpTmp = tmpWord;
	mySet.insert(tmpTmp);
      }
      myFile.close();
   }
   else
   {
      cout << "Unable to open file.";
   }

   // print each item in the set  
   cout << "\n\nGot it. Printing words in text file now: \n\n";
   for(it = mySet.begin(); it != mySet.end(); ++it){
      cout << " " << *it;
   }


   getchar();
   return 0;

}
