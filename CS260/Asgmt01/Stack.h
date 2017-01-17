#ifndef STACK_H
#define STACK_H
#include "Potion.h"

class Stack
{
public:
// constructors and destructor
Stack(int stackSize);
Stack(const Stack& thisStack);
~Stack();

// stack operations
bool isEmpty() const;
bool isFull() const;

bool push(const Potion& potion);

bool pop(Potion& potion);

bool getTop(Potion& potion);

const Stack& Stack::operator=(const Stack& stack);
//friend ostream& operator<<(ostream& out, Stack& stack);

private:

Potion* items;
int top;
int sCount;
int sSize;
};

#endif