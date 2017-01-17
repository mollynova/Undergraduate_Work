// add code to these functions to make Quack do something useful

#include "memoryleakdetect.h"		// this must be the first #include in each of your .cpp files
#include "quack.h"
#include <iostream>
using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]("Molly Novash");

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION(false);

Quack::Quack(int capacity, int growBy) :
	capacity(capacity),
	growBy(growBy),
	nItems(0),
	items(new char[capacity]),
	front(NULL),
	back(NULL)
{
	for (int i = 0; i < capacity; i++)
	{
		items[i] = 0xCD;
	}
}

Quack::~Quack(void)
{
	delete[] items;
}

// items are pushed to successively LOWER slots in the circular array
// (except for when the beginning of the array "wraps around" to the end)
bool Quack::pushFront(const char ch)
{
	// if list is empty
	if (itemCount() == 0)
	{
		items[0] = ch;
		front    = 0;
		back     = 0;
		nItems++;
		return false;
	}

	// if list is full
	if (itemCount() == capacity)
	{
		return false;
	}

	// if list not empty but it has room left in it
	if (itemCount() != 0)
	{
		if (front == 0)
		{
			items[capacity - 1] = ch;
			front = (capacity - 1);
			nItems++;
			return false;
		}
		else if (front > 0)
		{
			items[front - 1] = ch;
			front = (front - 1);
			nItems++;
			return false;
		}
	}
	
	return false;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch) 
{
	// if list is empty

	if (itemCount() == 0)
	{
		items[0] = ch;
		front    = 0;
		back     = 0;
		nItems++;
		return false;
	}

	// if list is full
	if (itemCount() == capacity)
	{
		return false;
	}

	// if list is not empty
	if (itemCount() != 0)
	{
		if (back == (capacity - 1))
		{
			items[0] = ch;
			back     = 0;
			nItems++;
			return false;
		}
		else if (back >= 0 && back < (capacity - 1))
		{
			items[back + 1] = ch;
			back++;
			nItems++;
			return false;
		}
	}
	return false;
}

bool Quack::popFront(char& ch)
{
	// if list is empty, can't pop
	if (itemCount() == 0)
	{
		return false;
	}

	// pop by incrementing front, increment nItems
	ch = this->items[front];
	
	if (front < (capacity - 2))
	{
		front++;
		nItems--;
		return true;
	}
	else if (front == (capacity - 1))
	{
		front = 0;
		nItems--;
		return true;
	}
	return false;
}

bool Quack::popBack(char& ch)
{
	if (itemCount() == 0)
	{
		return false;
	}

	ch = this->items[back];
	if (back == 0)
	{
		back = (capacity - 1);
		nItems--;
		return true;
	}

	else if (back < capacity)
	{
		back--;
		nItems--;
		return true;
	}
	return false;
}

void Quack::rotate(int r)
{
	if (nItems < capacity) { 
		if (r < 0) {
			int abs = r*(-1);
			for (int i = 0; i < abs; i++) {
				if ((back - i) < 0)
				{
					items[(back + 1 - i) % capacity] = items[capacity + back - i];
				}
				else if ((back - 1) > 0)
				{
					items[(back + 1 - i) % capacity] = items[back - i];
				}
			}
		}
		else {
			for (int i = 0; i < r; i++){
				items[(back + 1 + i) % capacity] = items[(front + i) % capacity];
			}
		}
	}
	if ((front + r) > 0)
	{
		front = (front + r) % capacity; 
	}
	else {
		front = front + r + capacity;
	}

	back = (back + r) % capacity;
}

void Quack::reverse(void)
{
	if ((capacity % 2) == 1) // if list has odd number of items
	{
		// move data around in array (into reverse order)
		int modOp = (capacity - 1);

		for (int i = 0; modOp != 0; i++)
		{
			char dum = items[(capacity - 1 - i - modOp)];
			items[(capacity - 1 - i - modOp)] = items[(capacity - 1 - i)];
			items[(capacity - 1 - i)] = dum;
			modOp = modOp - 2; 
		}
	}
	else { // if list has even number of items.
		   // (I Could have put these into one, without using an if/else
		   // but for this program it would make it run slower I think
		   // maybe not even perceptibly, I don't know)
		int modOp = (capacity - 1);

		for (int i = 0; modOp >= 1; i++)
		{
			char dum = items[(capacity - 1 - i - modOp)];
			items[(capacity - 1 - i - modOp)] = items[(capacity - 1 - i)];
			items[(capacity - 1 - i)] = dum;
			modOp = modOp - 2;
		}
	}
}

int	Quack::itemCount(void)
{
	return nItems;
}


ostream& operator<<(ostream& out, Quack *q)
{
	int newIt = q->front;

	if (q->itemCount() == 0)
	{
		out << "quack: empty" << endl << endl;
	}
	else {
		out << "quack: ";

		for (int i = 0; i < (q->nItems); i++)
		{
			if (newIt == (q->capacity))
			{
				newIt = 0;
				i--;
			}

			else if (newIt == q->back)
			{
				out << q->items[newIt];
			}
			else {
				out << q->items[newIt] << ", ";
				newIt++;
			}
		}
		// returning out is ALWAYS required for an operator<< overload
		out << endl << endl;
	}
	return out;
}