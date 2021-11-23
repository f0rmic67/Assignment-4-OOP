#include <iostream>
#include <string>
#include "clock.h"

using namespace std;

int main() {
	
	Clock grandfather, wall;
	
	int choice, addmin, compnum;
	bool compare;
	
	do
	{
		cout << "Please enter the number of your desired action.\n" << endl;
		cout << "1. Set the time\n2. Display the current time\n3. Advance one hour\n4. Advance one minute\n5. Add specific number of minutes\n6. Compare two times \n7. Quit" << endl;
		cout << "Number: ";
	
		while(!(cin >> choice) || cin.peek() != '\n' || choice < 1 || choice > 7)
   		{	
    		cout << "\nPlease enter an integer between one and seven: ";
    		cin.clear();
    		cin.ignore(30000, '\n');            
   		}
   		
   		cin.ignore();   
   		
   		if(choice == 1)
   		{
   			cin >> grandfather;
   		}
   			
   		else if(choice == 2)
   			cout << grandfather;
   			
   		else if(choice == 3)
   			grandfather.addhour();
   			
   		else if(choice == 4)
   			grandfather.addminute();
   		
   		else if(choice == 5)
   		{
   			cout << "\nMinutes to add: ";
   			
   			while(!(cin >> addmin) || cin.peek() != '\n' || choice < 1)
   			{	
    			cout << "\nPlease enter an integer greater than zero: ";
    			cin.clear();
    			cin.ignore(30000, '\n');            
   			}
   			
   			grandfather = grandfather + addmin;
	    }
	    
	    else if(choice == 6)
	    {
	    	cin >> wall;
	    	
	    	do
			{
	    		cout << "\nHow would you like to compare the times?\n\n";
	    		cout << "1. saved > new \n2. saved < new \n3. saved == new \n4. saved >= new\n5. saved <= new \n6. saved != new \n7. exit compare \n\n";
	    	
	    		cout << "Choice: ";
	    	
	    		while(!(cin >> compnum) || cin.peek() != '\n' || choice < 1 || choice > 7)
   				{	
    				cout << "\nPlease enter an integer between one and seven: ";
    				cin.clear();
    				cin.ignore(30000, '\n');            
   				}
   			
   				if(compnum == 1)
   				{
   					compare = grandfather > wall;
   				
   					cout << "\nsaved > new: ";
					wall.printbool(compare);
					
					cout << "\n";
		    	}
		    
		  	   else if(compnum == 2)
		 	    {
		  	  		compare = grandfather < wall;
		    	
		  	 	 	cout << "\nsaved < new: ";
		  	 	 	wall.printbool(compare);
		  	 	 	
		  	 	 	cout << "\n";
				}
			
				else if(compnum == 3)
				{
					compare = grandfather == wall;
				
					cout << "\nsaved == new: ";
					wall.printbool(compare);
					
					cout << "\n";
				}
			
				else if(compnum == 4)
				{
					compare = grandfather >= wall;
				
					cout << "\nsaved >= new: ";
					wall.printbool(compare);
					
					cout << "\n";
				}
			
				else if(compnum == 5)
				{
					compare = grandfather <= wall;
				
					cout << "\nsaved <= new: ";
					wall.printbool(compare);
					
					cout << "\n";
				}
			
				else if(compnum == 6)
				{
					compare = grandfather != wall;
				
					cout << "\nsaved != new: ";
					wall.printbool(compare);
					
					cout << "\n";
				}	
			
				else if(compnum == 7)
				{
					cout << "\nExiting compare..." << endl;
				}
			}
			while(compnum != 7);
		}
   			
   		else if(choice == 7)
   			cout << "\nExiting..." << endl;
   			
   		cout << endl;
	}
	while(choice != 7);
	
	return 0;
}
