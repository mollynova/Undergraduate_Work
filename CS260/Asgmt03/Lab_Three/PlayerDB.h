#ifndef PLAYERDB_H
#define PLAYERDB_H
#include <iostream>
#include "HashTable.h"
#include "Player.h"
using namespace std;

class PlayerDB
{
public:
	PlayerDB(ostream &out);
	PlayerDB();

	bool AddPlayer(Player& player);
	bool RemovePlayer(char * name);
	Player* FetchPlayer(char * name);
	void PrintDiagnostics();


private:
	// Note*1 (see EOF(PlayerDB.h))
	HashTable hashTable;
	ostream * m_out;
};

#endif

// Note*1: I assumed immediately when I saw pdb(cout) in main.cpp that
// we'd need an 'ostream &out' in the playerdb constructor, and I looked it up
// online and made my own ostream under 'private,' but since I haven't been able
// to debug this program because of that error I couldn't figure out how to fix,
// I wasn't able to play around with it and figure out how to make my ostream work,
// so I just used cout. I just included it in there because I was planning on using 
// m_out