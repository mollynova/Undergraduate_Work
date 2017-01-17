#include "memoryleakdetect.h"		// this must be the first #include in each of your .cpp files
#include "date.h"

using namespace std;

Date::Date(Month month, int day, int year)
{
}

Date::Date()
{
}

Date::~Date(void)
{
}

ostream& operator<<(ostream& out, const Date& d)
{
	return out;
}
