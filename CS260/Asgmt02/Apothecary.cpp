#include"Apothecary.h"
#include"main.h"

Apothecary::Apothecary(int queueSize, int stackSize)
{
    ShopInventory = new Stack(stackSize);
    OrdersPending = new Queue(queueSize);
}

Apothecary::~Apothecary()
{
    delete ShopInventory;
    delete OrdersPending;
}

Apothecary::Apothecary(Apothecary& apothecary)
{
    ShopInventory = apothecary.ShopInventory; // Stack
    OrdersPending = apothecary.OrdersPending; // Queue
}

bool Apothecary::OrderPotion(PotionType type)
{
    // orders go into our queue
    // we just need to make a new potion of that type and enqueue it
    
    Potion potion(type);
	//OrdersPending->enqueue(potion);
	
	if(OrdersPending->enqueue(potion))
	{ 
		return true;
	} else {
		return false;
	}
}

int Apothecary::MakePotions()
{
    // first we need to check if shelf(stack) is full
	int PotionCount = 0;
    Potion potion;
  
	for(PotionCount; !OrdersPending->isEmpty(); PotionCount++)
	{
    if(!OrdersPending->isEmpty())
        if(ShopInventory->isFull() == false)
		{
			OrdersPending->dequeue(potion);
			ShopInventory->push(potion);
			cout << "Made a " << PotionTypeString(potion.GetType()) << " potion." << endl;
		}
        else if(ShopInventory->isFull() == true)
		{
            cout << "The shelf of potions is full. You can't make any more until somebody buys some." << endl;
			return 0;
          
		}
	}
	return PotionCount;
}

bool Apothecary::BuyPotion(Potion& potion)
{
	//Potion potion(potion);
    // returns true if we bought the potion, false if not
    return ShopInventory->pop(potion);
}

const Apothecary& Apothecary::operator=(Apothecary& apothecary)
{
	if(this != &apothecary)
	{
		OrdersPending = apothecary.OrdersPending;
		ShopInventory = apothecary.ShopInventory;
	}

	return * this;
}
	