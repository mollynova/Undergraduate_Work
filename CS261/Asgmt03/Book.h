#pragma once

#include "item.h"

class Book : public Item
{
public:
	
	Book(const string& title, const string& author, const int nPages)
		: Item(title, author, nPages)
	{
	}

	~Book(void);
};

