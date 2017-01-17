#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "ChainNode.h"
#include "KeyedItem.h"
#include "Player.h"

typedef KeyedItem TableItemType;

class HashTable
{
public:
	// constructors and destructor
	// format pulled from pg. 699 of the book
	HashTable();
	virtual ~HashTable();

	// member operations
	bool thisListIsEmpty(int index);
	void tableInsert(Player& player, KeyType name);
	bool tableDelete(KeyType name);
	bool tableRetrieve(char* name, Player& player);

	int tableGetSize() { return HASH_TABLE_SIZE; }
	int tableGetEntries() { return entries; }
	node** GetTable() { return table; }
	int hashIndex(KeyType searchWithName) const;

private:
	
	static const int HASH_TABLE_SIZE = 3;
	node** table;
	int entries; // number of entries in each linked list
	int size; // size of ADT table
};

#endif