#include <string>

#include "Bill.hpp"

/************************************************
** Member function definitions
************************************************/

// ADD IMPLEMENTATION OF CONSTRUCTOR FOR CLASS Bill
Bill::Bill(const std::string & name,
		const double & dues,
		const unsigned int & month,
		const unsigned int & day):payee_(name),amount_due_(dues),due_month_(month),due_day_(day){} //both a default and a parameter constructor that sets the values pf the Bill struct variables

bool Bill::isOverdue(const unsigned int &currMonth, const unsigned int& currDay) {

						 unsigned int check = currMonth-due_month_; //Calculates the difference between the current and due date month
						 if(check < -1||check >= 1) return true; //If the difference of the current month was less than -1 or if the difference was greater than one, then it’s overdue so returns true
						 if(currDay > due_day_) return true; //see of the current day is greater than the due date, returns true for overdue

	// returns true if the due date for the bill is past
  // the date (month and day) given as parameters
  // false otherwise

// TO BE COMPLETED
return false; //returns false if it is not overdue
}

// This function member implementation is complete
unsigned int Bill::daysOverdue(const unsigned int &currMonth,
			       const unsigned int& currDay ) {
  // computes the number of days elapsed between the due date
  // of the bill and the date (month and day) given as parameters
  if (due_month_ > currMonth )
    return 0;
  if (due_month_ == currMonth ) {
    if (due_day_ >= currDay)
      return 0;
    else
      return (currDay - due_day_);
  }
  unsigned int counter=0;
  unsigned int tempMonth=due_month_;
  unsigned int tempDay = due_day_;
  while (tempMonth < currMonth) {
    switch (tempMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      counter = counter + 31 - tempDay;
      break;
    case 2:
      counter = counter + 28 - tempDay;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      counter = counter + 30 - tempDay;
    }
    tempDay = 0;
    tempMonth++;
  }
  counter = counter + currDay;

  return counter;
}
