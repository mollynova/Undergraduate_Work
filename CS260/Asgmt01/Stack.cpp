#include "Stack.h"
#include<cstdlib>
#include<fstream>
#include<assert.h>


Stack::Stack(int stackSize) :
top(-1),
sSize(stackSize),
sCount(0)
{
    items = new Potion[stackSize];
}

Stack::~Stack()
{
    delete [] items;
}

Stack::Stack(const Stack& thisStack)
{
	top = thisStack.top;
	sSize = thisStack.sSize;

	items = new Potion[sSize];
	for(int i = 0; i <= thisStack.top; i++)
	{
		items[i] = thisStack.items[i];
	}
}

bool Stack::push(const Potion& potion) 
{
	//Potion potion(potion);
	if(sCount == sSize)
	{
		return false;
	} else {
		items[top + 1] = potion;

		if((top + 1) > sSize) {
			top = top & sSize;
		} else {
			top++;
		}
		sCount++;
		return true;
	}
}

bool Stack::pop(Potion& potion)
{
	if(sCount == 0)
	{
		return false;
	} else {
		
		if(top < (sSize - 1)){
			top++;
			//HERES where i change something
			sCount--;
		} else if(top == (sSize - 1))
		{
			top = 0;
			sCount --;
		}
		return true;
	}
}

bool Stack::isEmpty() const
{
	return sCount == 0;
}

bool Stack::isFull() const
{
	return sSize == sCount;
}

bool Stack::getTop(Potion& potion)
{
	if(sCount == 0)
	{
		return false;
	} else {
		potion = items[top];
		return true;
	}
}

// the jury's out on whether this is necessary
const Stack& Stack::operator=(const Stack& stack)
{
	
	if(this != &stack)
	{
		// first, wipe *this
		delete [] this->items;

		// change sizing/pointer of *this to match stack
		this->top = stack.top;
		this->sCount = stack.sCount;
		this->sSize = stack.sSize;

		// make new array
		items = new Potion[sSize];

		// copy all stuff from stack into *this array
		for(int i = 0; i < sSize; i++)
		{
			items[i] = stack.items[i];
		}
	}

	return * this;
	
}

// I don't think I need one of these because the program never outputs the 
// contents of the stack in output.txt
/*ostream& operator<<(ostream& out, Stack& stack)
{

}*/