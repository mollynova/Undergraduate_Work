#pragma once

#include "item.h"
#include <set>

class Movie : public Item
{
public:
	Movie(const string title, const string director, const int nScenes)
		: Item(title, director, nScenes), cast()
	{
	}

	~Movie(void);

	set<string> getCast() { return cast; }
	void addMember(string member);
	void sortMembers();

private:
	set<string> cast;
};

