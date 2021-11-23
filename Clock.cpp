#include <iostream>
#include <string>
#include <stdlib.h>
#include "clock.h"

using namespace std;

Clock::Clock()  //automatically sets clock time to midnight
{
	hour = 12;
	minute = 00;
	period = "AM";
	
	return;
}

void Clock::setperiod(const string p)
{
	if(p == "AM" || p == "PM")
		period = p;
		
	return;
}

void Clock::sethour(const int h)
{
	if(h >= 1 && h <= 12)
		hour = h;
		
	return;
}

void Clock::setminute(const int m)
{
	if(m >= 0 && m < 60)
		minute = m;
		
	return;
}

void Clock::addhour()
{
	if(hour == 12)  //ensures clock hour never exits the bounds of 1-12
		hour = 1;
		
	else if(hour == 11)  //changes the period if necessary
	{
		if(period == "AM")
		{
			hour++;
			period = "PM";
		}
		else
		{
			hour++;
			period = "AM";
		}
	}
	
	else
		hour++;
		
	return;
}

void Clock::printbool(bool b1) const  //used to display relational operator results
{
	if(b1 == true)
		cout << "True";
	
	else
		cout << "False";
}

void Clock::addminute()
{
	if(minute == 59)   //checks if adding one minute will also adjust the hour
	{
		if(hour == 11)   //if hour is 11 and minutes are 59, increments and adjusts period
		{
			if(period == "AM")
			{
				minute = 0; 
				hour++;
				period = "PM";
			}
			else
			{
				minute = 0;
				hour++;
				period = "AM";
			}
		}
		
		else if(hour == 12)  //rolls back to 1:00 when time is 12:59
		{
			minute = 0;
			hour = 1;
		}
		
		else  //changes hour when minutes = 59
		{
			hour++;
			minute = 0;
		}
	}
	
	else    //adds one minute when no other adjustments are needed
		minute++;
	
}

string Clock::getperiod() const
{
	return period;
}

int Clock::gethour() const
{
	return hour;
}

int Clock::getminute() const
{
	return minute;
}

Clock operator+(const Clock& c1, const int& n1)  //overloaded to add specific number of minutes to time
{
	Clock answer;
	int hours, minutes;
	
	answer = c1;
	
	if(n1 > 0)
	{
		for(int count = 0; count < n1; count++)  //calls the addminute function for every minute the user wants to add
		{
			answer.addminute();
		}	
	}
	
	return answer;
}

bool operator>(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if((c1.hour > c2.hour && c1.period == c2.period) || (c1.period == "PM" && c2.period == "AM"))  //checks hours in the same period and hours in different periods
	{
		answer = true;
	}
	
	else if(c1.hour == c2.hour && c1.period == c2.period)  //checks times with the same hour + period
	{
		if(c1.minute > c2.minute)
		{
			answer = true;
		}
		else
			answer = false;
	}
	
	else
	{
		answer = false;
	}
	
	return answer;
}


bool operator<(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(operator>(c1, c2) == false && operator==(c1, c2) == false)  //uses > and == operators to determine answer
		answer = true;
		
	else
		answer = false;
		
	return answer;
}

bool operator==(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(c1.hour == c2.hour && c1.minute == c2.minute && c1.period == c2.period)
		answer = true;
		
	else 
		answer = false;
		
	return answer;
}

bool operator>=(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(operator>(c1, c2) || operator==(c1, c2))  //combines > and == operators
		answer = true;
		
	else
		answer = false;
		
	return answer;
}

bool operator<=(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(operator<(c1, c2) || operator==(c1, c2))  //combines < and == operators
		answer = true;
	
	else
		answer = false;
		
	return answer;

}

bool operator!=(const Clock& c1, const Clock& c2) 
{
	bool answer;
	
	if(!(operator==(c1, c2)))  //uses == operator
		answer = true;
	
	else
		answer = false;
		
	return answer;
}

ostream& operator<<(ostream& out, const Clock& c1)
{
	out << "\n" << c1.hour << ":";
	
	if(c1.minute < 10)     //adds zero before single-digit minutes in output
		out << "0" << c1.minute;
	else
		out << c1.minute;
		
	out << " " << c1.period << endl;
	
	return out;
}

istream& operator>>(istream& inp, Clock& c1)
{
	string time, hour1, minute1, period1;
	int colonIndex, spaceIndex, digitCheck, hour2, minute2;
	bool goodData = true;
	
	do
	{	
		cout << "\nPlease enter a time in the following format: 3:42 PM" << endl;
		cout << "Time: ";
		getline(inp, time);
			
		colonIndex = time.rfind(':');  //locates time format markers
		spaceIndex = time.rfind(' ');
		
		if(colonIndex != -1 && spaceIndex != -1) 
		{
			hour1 = time.substr(0, colonIndex);       //stores hour string
			minute1 = time.substr(colonIndex + 1, 2); //stores minute string
			period1 = time.substr(spaceIndex + 1, 2); //stores period string
			
			goodData = true;
		}
		else
			goodData = false;
		
		if(goodData == true)		
		{
			for(int count = 0; count < hour1.length(); count++) //checks hour string for good data
			{
				digitCheck = isdigit(hour1[count]); 
				
				if(digitCheck == 0)
					goodData = false;
			} 
		
			for(int count = 0; count < minute1.length(); count++) //checks minute string
			{
				digitCheck = isdigit(minute1[count]);
			
				if(digitCheck == 0)
					goodData = false;
			} 
			
			if(goodData == true)  //converts string data to int so it can be stored in Clock
			{
				
				hour2 = atoi(hour1.c_str());
				
				if(hour2 < 1 || hour2 > 12)
					goodData = false;
					
				minute2 = atoi(minute1.c_str());
				
				if(minute2 < 0 || minute2 > 59)
					goodData = false;
			}
			
			if(period1 != "AM" && period1 != "PM") //checks period string
				goodData = false;   
		}
		
		if(goodData == false)	
			cout << "\nIncorrect format, please enter time again." << endl;  //prompts the user to input new time in the case of bad data
	}
	while(goodData == false);
	
	c1.sethour(hour2);
	c1.setminute(minute2);   //sets input data to Clock
	c1.setperiod(period1);
	
	return inp;
}
