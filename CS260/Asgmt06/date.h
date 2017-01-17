// do not change this file

#pragma once

#include <ostream>

class Date
{
public:
	typedef enum {INVALID, JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
				  JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER}
	Month;

	Date(Month month, int day, int year);
	Date(void);								// default constructor
	~Date(void);

	friend std::ostream& operator<<(std::ostream& out, const Date& d);

private:
	Month	month;
	int		day;
	int		year;
};
