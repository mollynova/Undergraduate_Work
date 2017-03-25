#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Movie.h"


Movie::~Movie(void)
{
	cast.clear();
}

void Movie::addMember(string member) {
	cast.insert(member);
}

void Movie::sortMembers() {
	//don't think I need this actually
}