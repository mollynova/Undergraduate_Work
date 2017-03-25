#pragma once
#include<set>
#include "item.h"

class MusicAlbum : public Item
{
public:
	MusicAlbum(const string title, const string band, const int nSongs)
		: Item(title, band, nSongs) , members()
	{
	}

	~MusicAlbum(void);

	set<string> getMembers() { return members; }
	void addMember(string member);
	void sortMembers();

private:
	set<string> members;
};

