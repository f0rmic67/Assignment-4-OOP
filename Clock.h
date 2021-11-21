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
    void setperiod(const std::string);
    void sethour          (const int);
    void setminute        (const int);
    void settime                   ();
    void setbadinput     (const bool);
    void addhour                   ();
    void addminute                 ();

    // CONSTANT MEMBER FUNCTIONS
    std::string getperiod() const;
    int  gethour         () const;
    int  getminute       () const;
    bool getbadinput     () const;
    void display         () const;
    
    //OVERLOADED OPERATORS
    friend Clock operator+  (const Clock&, const int&);
    friend bool operator> (const Clock&, const Clock&);
    friend bool operator< (const Clock&, const Clock&);
    friend bool operator==(const Clock&, const Clock&);
    friend bool operator>=(const Clock&, const Clock&);
    friend bool operator<=(const Clock&, const Clock&);
    friend bool operator!=(const Clock&, const Clock&);
   /* friend ostream& operator<<(ostream&, const Clock&);
    friend istream& operator>>(istream&, const Clock&);*/
    
  private:
    string period;
    int  hour;
    int  minute;
    bool badinput;   //set to false with constructor, switches to true if bad data is input when setting the clock's time
};

#endif
