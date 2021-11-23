// CLASS PROVIDED:  Clock
//
// CONSTRUCTOR for the Clock class:
//   Clock()
//     Description:		constructor will initialize Clock objects
//     Preconditions:	none
//     Postcondition:	clock has been set to midnight, 12:00 AM
//
// MODIFICATION MEMBER FUNCTIONS for the Fraction class
//   void setperiod (const std::string)
//     Description:		set the period (am/pm) for the time of the clock
//     Precondition:	value is AM, am, Am, PM, pm, or Pm
//     Postcondition:	Clock period is set to string
//
//   void sethour (const int)
//     Description:		set the hour of the clock
//     Precondition:	value is between one and twelve
//     Postcondition:	hour of the clock is set to value
//
//   void setminute (const int)
//     Description:		set the minute of the clock
//     Precondition:	value is between zero and 59
//     Postcondition:	minute of the clock is set to value
//
//   void settime ()
//     Description:		set all aspects of the time to the clock
//     Precondition:	none
//     Postcondition:	clock hour, minute, and period are set
//
//   void addhour ()
//     Description:     adds one hour to the time of the clock
//     Precondition:    none
//     postcondition:   One hour is added to the time of the clock
//
//   void addminute ()
//     Description:     adds one minute to the time of the clock
//     Precondition:    none
//     postcondition:   one minute is added to the time of the clock
//
// CONSTANT MEMBER FUNCTIONS for the Fraction class
//   std::string getperiod () const
//     Description:		obtain period of the clock
//     Preconditions:	none
//     Postcondition:	period of the clock is returned
//
//   int  gethour () const
//     Description:		obtain hour of the clock
//     Preconditions:	none
//     Postcondition:	hour of the clock is returned
//
//   int  getminute () const
//     Description:		obtain minute of the clock
//     Preconditions:	none
//     Postcondition:	minute of the clock is returned
//
//   void display () const
//     Description:		displays the time of the clock; hour, minute, and period
//     Preconditions:	none
//     Postcondition:	time of the clock is printed
//
// FRIEND FUNCTIONS
//	friend Clock operator+(const Clock&, const Clock&)
//		Description:	adds specified number of minutes
//		Precondition:	needs a clock object
//		Postcondition:	minutes are added to the clock object
//
//	friend bool operator<(const Clock&, const Clock&);
//		Description:	determines if the time is less than the time of another clock
//		Precondition:	needs two clock objects to compare
//		Postcondition:	returns true if less than
//
//	friend bool operator>(const Clock&, const Clock&);
//		Description:	determines if the time is greater than the time of another clock
//		Precondition:	needs two clock objects to compare
//		Postcondition:	returns true if greater than
//
//	friend bool operato==(const Clock&, const Clock&);
//		Description:	determines if two clocks have equal time
//		Precondition:	needs two clock objcts to compare
//		Postcondition:	returns true if time is equal and false if time is not equal
//
//	friend bool operato!=(const Clock&, const Clock&);
//		Description:	determines if two clocks are not equal time
//		Precondition:	needs two clock objcts to compare
//		Postcondition:	returns true if time is not equal and false if time is equal
//
//	friend bool operator<=(const Clock&, const Clock&);
//		Description:	determines if the time is less than the time of another clock or equal
//		Precondition:	needs two clock objects to compare
//		Postcondition:	returns true if less than or equal
//
//	friend bool operator>=(const Clock&, const Clock&);
//		Description:	determines if the time is greater than the time of another clock or equal
//		Precondition:	needs two clock objects to compare
//		Postcondition:	returns true if greater than or equal
//
//	friend ostream& operator<< (ostream&, const Clock&);
//		Description:	allows a class object to be output
//		Precondition:	none
//		Postcondition:	the class object is displayed
//	
//	friend friend istream& operator>> (istream&, Clock&);
//		Description:	allows data to be input into object
//		Precondition:	user need to enter the data
//		Postcondition:	users data is stored

#include <iostream>
#ifndef CLOCK_H
#define CLOCK_H
#include <string>

using namespace std;

class Clock
{
  public:
    // CONSTRUCTOR
    Clock();

    // MODIFICATION MEMBER FUNCTIONS
    void setperiod(const std::string);
    void sethour          (const int);
    void setminute        (const int);
    void settime                   ();
    void addhour                   ();
    void addminute                 ();

    // CONSTANT MEMBER FUNCTIONS
    std::string getperiod() const;
    int  gethour         () const;
    int  getminute       () const;
    void display         () const;
    
    // FRIEND FUNCTIONS
    friend Clock operator+(Clock& , const int&);
    friend bool operator<(const Clock&, const Clock&);
    friend bool operator>(const Clock&, const Clock&);
    friend bool operator<=(const Clock&, const Clock&);
    friend bool operator>=(const Clock&, const Clock&);
    friend bool operator==(const Clock&, const Clock&);
    friend bool operator!=(const Clock&, const Clock&);
    
    friend ostream& operator<< (ostream&, const Clock&);
    friend istream& operator>> (istream&, Clock&);
    
  private:
    std::string period;
    int  hour;
    int  minute;
};

#endif
