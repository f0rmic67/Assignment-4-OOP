#include <iostream>
#include <string>
#include <stdlib.h>
#include "clock.h"

using namespace std;

Clock::Clock()
{
	hour = 12;
	minute = 00;
	period = "AM";
	badinput = false;
	
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

void Clock::setbadinput(const bool b)
{
	badinput = b;
	
	return;
}

void Clock::setminute(const int m)
{
	if(m >= 0 && m < 60)
		minute = m;
		
	return;
}

void Clock::settime()
{
	string time, hour1, minute1, period1;
	int colonIndex, spaceIndex, digitCheck, hour2, minute2;
	bool goodData = true;
	
	do
	{	
		cout << "\nPlease enter a time in the following format: 3:42 PM" << endl;
		cout << "Time: ";
		getline(cin, time);
			
		colonIndex = time.rfind(':');
		spaceIndex = time.rfind(' ');
		
		if(colonIndex != -1 && spaceIndex != -1)
		{
			hour1 = time.substr(0, colonIndex);
			minute1 = time.substr(colonIndex + 1, 2);
			period1 = time.substr(spaceIndex + 1, 2);
			
			goodData = true;
		}
		else
			goodData = false;
		
		if(goodData == true)		
		{
			for(int count = 0; count < hour1.length(); count++)
			{
				digitCheck = isdigit(hour1[count]);
				
				if(digitCheck == 0)
					goodData = false;
			} 
		
			for(int count = 0; count < minute1.length(); count++)
			{
				digitCheck = isdigit(minute1[count]);
			
				if(digitCheck == 0)
					goodData = false;
			} 
			
			if(goodData == true)
			{
				
				hour2 = atoi(hour1.c_str());
				
				if(hour2 < 1 || hour2 > 12)
					goodData = false;
					
				minute2 = atoi(minute1.c_str());
				
				if(minute2 < 0 || minute2 > 59)
					goodData = false;
			}
			
			if(period1 != "AM" && period1 != "PM")
				goodData = false;   
		}
		
		if(goodData == false)	
			cout << "\nIncorrect format, please enter time again." << endl;
	}
	while(goodData == false);
	
	sethour(hour2);
	setminute(minute2);
	setperiod(period1);
	
	return;
}

void Clock::addhour()
{
	if(hour == 12)
		hour = 1;
		
	else if(hour == 11)
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

void Clock::addminute()
{
	if(minute == 59)
	{
		if(hour == 11)
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
		
		else if(hour == 12)
		{
			minute = 0;
			hour = 1;
		}
		
		else
		{
			hour++;
			minute = 0;
		}
	}
	
	else
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

bool Clock::getbadinput() const
{
	return badinput;	
}

void Clock::display() const
{
	cout << "\n" << hour << ":";
	
	if(minute < 10)
		cout << "0" << minute;
	else
		cout << minute;
		
	cout << " " << period << endl;
	
	return;
}

Clock operator+(const Clock& c1, const int& n1)  //overloaded to add specific number of minutes to time
{
	Clock answer;
	int hours, minutes;
	
	answer = c1;
	
	if(n1 > 0)
	{
		for(int count = 0; count < n1; count++)
		{
			answer.addminute();
		}	
	}
	
	return answer;
}

bool operator>(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if((c1.hour > c2.hour && c1.period == c2.period) || (c1.period == "PM" && c2.period == "AM"))
	{
		answer = true;
		return answer;
	}
	
	else if(c1.hour == c2.hour && c1.period == c2.period)
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
		return false;
	}
	
	return answer;
}


bool operator<(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(operator>(c1, c2) == false && operator==(c1, c2) == false)
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
	
	if(operator>(c1, c2) || operator==(c1, c2))
		answer = true;
		
	else
		answer = false;
		
	return answer;
}

bool operator<=(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(operator<(c1, c2) || operator==(c1, c2))
		answer = true;
	
	else
		answer = false;
		
	return answer;

}

bool operator!=(const Clock& c1, const Clock& c2)
{
	bool answer;
	
	if(!(operator==(c1, c2)))
		answer = true;
	
	else
		answer = false;
		
	return answer;
}
/*
ostream& operator<<(ostream& out, const Clock& c1)
{
	out << "\n" << c1.hour << ":";
	
	if(c1.minute < 10)
		out << "0" << c1.minute;
	else
		out << c1.minute;
		
	out << " " << c1.period << endl;
	
	return out;
}

istream& operator>>(istream& inp, Clock& c1)
{
	string temp;
	
	getline(inp, temp);
	
	c1.settime(temp);
	
	return inp;
}
*/
