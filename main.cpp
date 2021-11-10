#include <iostream>
#include <string>
#include "clock.h"

using namespace std;

int main() {
	
	Clock grandfather;
	
	int choice;
	
	do
	{
		cout << "Please enter the number of your desired action.\n" << endl;
		cout << "1. Set the time\n2. Display the current time\n3. Advance one hour\n4. Advance one minute\n5. Quit" << endl;
		cout << "Number: ";
	
		while(!(cin >> choice) || cin.peek() != '\n' || choice < 1 || choice > 5)
   		{	
    		cout << "\nPlease enter an integer between one and five: ";
    		cin.clear();
    		cin.ignore(30000, '\n');            
   		}
   		
   		cin.ignore();   //Without this ignore, getline in settime function will run without user input
   		
   		if(choice == 1)
   			grandfather.settime();
   			
   		else if(choice == 2)
   			grandfather.display();
   			
   		else if(choice == 3)
   			grandfather.addhour();
   			
   		else if(choice == 4)
   			grandfather.addminute();
   			
   		else if(choice == 5)
   			cout << "\nExiting..." << endl;
   			
   		cout << endl;
	}
	while(choice != 5);
	
	return 0;
}
