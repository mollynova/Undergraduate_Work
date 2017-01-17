#include "PlayerDB.h"
#include "ChainNode.h"
#include "Player.h"
#include <iostream>

PlayerDB::PlayerDB() :
m_out(&cout)
{
}

PlayerDB::PlayerDB(ostream& out) :
m_out(&out)
{
}

//::~PlayerDB()
//{
//}

bool PlayerDB::AddPlayer(Player& player)
{
	// pull name out of player object so we can call tableInsert
	char* thisName = player.GetName();

	// print our "attempting" message
	cout << "Attempting to add player \"" << thisName << "\" to the database -- ";

	// check to see if player is already in the database

	// if it is in the database
	if(hashTable.tableRetrieve(thisName, player))
	{
		cout << "Failed." << endl << endl;
		return false;
	}

	// if it's not in the database
	/*if(!hashTable.tableRetrieve(thisName, player))
	{
		// insert player into DB, print success message
		hashTable.tableInsert(player, thisName);
		cout << "Success!" << endl << endl;
		return true;
	}

	// that player was already in the database 
	return false;*/
	else {
		// that player was not in the database; we can add them
		hashTable.tableInsert(player, thisName);
		cout << "Success!" << endl << endl;
		return true;
	}

}

bool PlayerDB::RemovePlayer(char * name)
{
	// out "attempting" message
	cout << "Removing player \"" << name << "\" from the database -- ";

	// if name is successfully deleted from list
	if(hashTable.tableDelete(name))
	{
		cout << "Success!" << endl << endl;
		return true;
	}
	else if(!hashTable.tableDelete(name))
	{
		cout << "Failed." << endl << endl;
	}
	// else name wasn't successfully deleted
	return false;
}

Player* PlayerDB::FetchPlayer(char * name)
{
	// make an instance of player to return
	Player *player = NULL;

	cout << "Fetching player \"" << name << "\" -- ";

    if(hashTable.tableRetrieve(name, *player)){
        cout << "Success!" << endl;
	}
    else {
        cout << "Failed." << endl;
	}
    return player;
}

void PlayerDB::PrintDiagnostics()
{
	// *Note1: See EOF (PlayerDB.cpp)
	// Print the basics
	cout << "====================" << endl << endl;
	cout << "Hash Table Diagnostics" << endl << endl << endl;
	cout << "Table Size: " << hashTable.tableGetSize() << endl << endl;
	cout << "Number of Entries: " << hashTable.tableGetEntries() << endl << endl;
	
	// Go through each table index position
	for(int i = 0; i < hashTable.tableGetSize(); i++)
	{
		// For each slot, print slot[i]
		cout << "Slot[" << i << "]:" << endl << endl;
		// If the list is empty, out empty
		if(hashTable.thisListIsEmpty(i))
		{
			cout << "    EMPTY" << endl << endl;
		} 
		// if the list is not empty, out names in it
		else if(!hashTable.thisListIsEmpty(i))
		{
			// pointer to first item in table[i]
			node* curr = hashTable.GetTable()[i];
			//int b = i;
			// while we're not at the end of the list
			while(curr != NULL)
			{
				cout << "    " << curr->GetPlayer().GetName() << " [";
				cout << curr->GetPlayer().GetLevel() << "]" << endl << endl;
				
				curr = curr->getNext();
			}
		}
	}

	cout << "====================" << endl << endl;
}
			
// *Note1:
	// I realized partway through that it would be better to do these calcs
	// in HashTable.cpp, but I wanted to get some practice with pointers and syntax so I 
	// just decided to see if I could make it work in PlayerDB.cpp
