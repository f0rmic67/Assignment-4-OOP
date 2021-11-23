// CLASS PROVIDED:  Clock
//
// CONSTRUCTOR for the Clock class:
//   Clock()
//     Description:		constructor will initialize Clock objects
//     Preconditions:	none
//     Postcondition:	clock has been set to midnight, 12:00 AM
//
// MODIFICATION MEMBER FUNCTIONS for the Clock class
//   void setperiod (const string)
//     Description:		set the period (am/pm) for the time of the clock
//     Precondition:	value is AM or PM
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
// CONSTANT MEMBER FUNCTIONS for the Clock class
//   string getperiod () const
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
//   void printbool (const bool) const
//     Description:		displays True or False depending on the state of the passed bool
//     Preconditions:	bool is true or false
//     Postcondition:	true or false is printed
//
// OVERLOADED OPERATORS for the Clock class
//   friend Clock operator+ (const Clock&, const int&);
//     Description:     Add a specified number of minutes to the time
//     Preconditions:   None
//     Postcondition:   user-input number of minutes are added
//
//   friend bool operator> (const Clock&, const Clock&);
//     Description:     check if time of one clock object is greater than time of second object
//     Preconditions:   two initialized clock objects
//     Postcondition:   boolean is returned
//
//   friend bool operator< (const Clock&, const Clock&);
//     Description:     check if time of one clock object is less than time of second object
//     Preconditions:
//     Postcondition:   boolean is returned
//
//   friend bool operator== (const Clock&, const Clock&);
//     Description:     check if time of one clock object is equal to time of second object
//     Preconditions:   two initialized clock objects
//     Postcondition:   boolean is returned
//
//   friend bool operator>= (const Clock&, const Clock&);
//     Description:     check if time of one clock object is greater than or equal to time of second object
//     Preconditions:   two initialized clock objects
//     Postcondition:   boolean is returned
//
//   friend bool operator<= (const Clock&, const Clock&);
//     Description:     check if time of one clock object is less than or equal to time of second object
//     Preconditions:   two initialized clock objects
//     Postcondition:   boolean is returned
//
//   friend bool operator!= (const Clock&, const Clock&);
//     Description:     check if time of one clock object is not equal to time of second object
//     Preconditions:   two initialized clock objects
//     Postcondition:   boolean is returned
//
//   friend ostream& operator<< (ostream&, const Clock&);
//     Description:     Displays the time set to the calling clock object
//     Preconditions:   initialized clock object
//     Postcondition:   time is printed
//
//   friend istream& operator>> (istream&, Clock&); 
//     Description:     allows the user to set the clock's time
//     Preconditions:   initialized clock object
//     Postcondition:   time is set
//

#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <iostream>

using namespace std;

class Clock
{
  public:
    // CONSTRUCTOR
    Clock();

    // MODIFICATION MEMBER FUNCTIONS
    void setperiod     (const string);
    void sethour          (const int);
    void setminute        (const int);
    void addhour                   ();
    void addminute                 ();

    // CONSTANT MEMBER FUNCTIONS
    string getperiod        () const;
    int  gethour            () const;
    int  getminute          () const;
    void printbool(const bool) const;
    
    //OVERLOADED OPERATORS
    friend Clock operator+  (const Clock&, const int&);
    friend bool operator> (const Clock&, const Clock&);
    friend bool operator< (const Clock&, const Clock&);
    friend bool operator==(const Clock&, const Clock&);
    friend bool operator>=(const Clock&, const Clock&);
    friend bool operator<=(const Clock&, const Clock&);
    friend bool operator!=(const Clock&, const Clock&);
    friend ostream& operator<<(ostream&, const Clock&);
    friend istream& operator>>      (istream&, Clock&); 
    
  private:
    string period;
    int  hour;
    int  minute;
};

#endif
