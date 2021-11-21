#include <iostream>
#include <string>
#include "clock.h"

using namespace std;

int main() {
	
	Clock grandfather;
	Clock newClock;
	
	int choice;
	
	do
	{
		cout << "Please enter the number of your desired action.\n" << endl;
		cout << "1. Set the time\n2. Display the current time\n3. Advance one hour\n4. Advance one minute\n"
			 << "5. Advance many minutes\n6. Check if equal\n7. Check if not equal\n8. If greater than\n9. If less than\n"
			 << "10. If greater than or equal\n11. If less than or equal\n12. Quit" << endl;
		cout << "Number: ";
	
		while(!(cin >> choice) || cin.peek() != '\n' || choice < 1 || choice > 12)
   		{	
    		cout << "\nPlease enter an integer between one and twelve: ";
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
   			{
   			int addmins = 0;
			cout << "Enter the number of minutes to add" << endl;
			cin >> addmins;
			grandfather = grandfather + addmins;
			}
   				
   		else if(choice == 6)
		    if (grandfather == newClock)
		    	cout << "They are equal.\n";
		    else
		    	cout << "they are not equal.\n";
		 	
		else if(choice == 7)	
			if (grandfather != newClock)
				cout << "They are definitely not equal.\n";
			else
				cout << "They are definitely equal.\n";
			
		else if(choice == 8)
			if (grandfather == newClock)
				cout << "Your time is actually equal to 6:00 AM\n";
			else if (grandfather > newClock)
				cout << "Your time is greater than 6:00 AM\n";
			else
				cout << "Your time is less than 6:00 AM\n";
				
		else if(choice == 9)
			if (grandfather == newClock)
				cout << "Your time is absolutely equal to 6:00 AM\n";
			else if (grandfather < newClock)
				cout << "Your time is less than 6:00 AM\n";
			else
				cout << "Your time is greater than 6:00 AM\n";
				
		else if(choice == 10)
			if (grandfather >= newClock)
				cout << "Your time is greater than or equal to 6:00 AM\n";
			else 
				cout << "Your time is less than 6:00 AM\n";
				
		else if(choice == 11)
			if (grandfather <= newClock)
				cout << "Your time is less than or equal to 6:00 AM\n";
			else
				cout << "Your time is greater than 6:00 AM\n";
				
   		else if(choice == 12)
   			cout << "\nExiting..." << endl;
   			
   		cout << endl;
	}
	while(choice != 12);
	
	return 0;
}
