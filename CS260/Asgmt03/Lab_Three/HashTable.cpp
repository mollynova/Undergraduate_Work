#include<iostream>
#include<cstring>
#include"HashTable.h"
#include"ChainNode.h"


HashTable::HashTable() :
	size(HASH_TABLE_SIZE),
	entries(0),
	table(new node*[HASH_TABLE_SIZE])
	{
		for(int i = 0; i < HASH_TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}

HashTable::~HashTable()
{
	// first, we have to delete each item from each linked list
	// we need two pointers to do this
	int i = 0;

	for(i; i < HASH_TABLE_SIZE; i++) 
	{
		node* head = table[i];
		node* curr;

		while(head)
		{
			curr = head->next;
			head->next = NULL;
			delete head;
			head = curr;
		}
	}

	// delete the whole array table
	delete [] table;
}

bool HashTable::thisListIsEmpty(int index)
{
	if(table[index] == NULL)
		return true;
	else
		return false;
}

int HashTable::hashIndex(KeyType searchWithName) const
{
	// handles value of solution for searchWithName[0]
	unsigned int solution = int(searchWithName[0]);

	int nameLength = strlen(searchWithName);
	// handles value of solution for all other indices of searchWithName
	for(int i = 1; i < nameLength; i++)
	{
		solution = solution * 32 + searchWithName[i];
	}

	return solution % HASH_TABLE_SIZE;
}

void HashTable::tableInsert(Player& player, KeyType name)
{
	int index = hashIndex(name);
	node* insert = new node(player);

	insert->next = table[index];
	table[index] = insert;
	entries++;
}

bool HashTable::tableDelete(KeyType name) 
{
	// Hash the item to be deleted so we know what table pos it's in
	int index = hashIndex(name);

	// Declare variables
	node* curr = table[index];
	node* prev = NULL;
	//char* currName;

	if(table[index])
	{
		
		// if node to be deleted is first in linked list
		if(strcmp(name, curr->player.GetName()) == 0)
		{
			table[index] = curr->next;
			curr->next = NULL;
			delete curr;
			entries--;
			return true;
		}

		// if node is in the middle of the linked list
		while(curr->next != NULL)
		{
			if(strcmp(name, curr->player.GetName()) != 0 )
			{
				prev = curr;
				curr = curr->next;
			} else if(strcmp(name,curr->player.GetName()) == 0)
			{
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				entries--;
				return true;
			}
		}
	
		// if node to be deleted is last in the linked list
		if(curr->next == NULL && strcmp(name, curr->player.GetName()) == 0)
		{
			prev->next = NULL;
			delete curr;
			entries--;
			return true;
		}
	}
	else {
		return false;
	}
	return false;
}


bool HashTable::tableRetrieve(char* name, Player& player)
{
	
    //calculate the retrieval position (the index of the array)
    int index = hashIndex(name);
	node* curr = table[index];
	char* thisPlayer;

	while(curr)
	{
		thisPlayer = curr->player.GetName();

		if(strcmp(name, thisPlayer) == 0)
        {
            //find match and return the Player
           // player = curr->player;
            return true;
        }
        else
            curr = curr->next;
    }

    //Player is not in the table
    return false;
   
}


