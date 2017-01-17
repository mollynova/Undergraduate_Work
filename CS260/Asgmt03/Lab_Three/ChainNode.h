#include <iostream>
#include"Player.h"

#ifndef NODE_H
#define NODE_H

class node
{
public:
	Player GetPlayer() { return player; }
	node(const Player& player);
	node* getNext() { return next; }
private: 
	Player player;
	node *next;

	friend class HashTable;
};

#endif