#include"main.h"
#include"Queue.h"
#include"Stack.h"
#include<stdlib.h>
#ifndef APOTHECARY_H
#define APOTHECARY_H

class Apothecary
{
public:

// constructor for making our deep copy
Apothecary(Apothecary& apothecary);

// constructor for making a new instance of apothecary
Apothecary(int stackSize, int queueSize);

~Apothecary();

const Apothecary& operator=(Apothecary& apothecary);

// member functions

bool OrderPotion(PotionType type);

int MakePotions();
//bool BuyPotion();
//Potion BuyPotion();
bool BuyPotion(Potion& potion);

private:

Stack *ShopInventory;
Queue *OrdersPending;

};

#endif