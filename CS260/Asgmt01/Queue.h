#ifndef QUEUE_H
#define QUEUE_H
#include"Potion.h"


class Queue
{
public:
// constructors and destructor
Queue(int queueSize);
Queue(const Queue& queue);
~Queue();

// member functions
bool enqueue(const Potion& potion);
bool dequeue(Potion& potion);
bool isFull();
bool isEmpty();
bool getFront(Potion& potion) const;

const Queue& operator=(const Queue& queue);
friend ostream& operator<<(ostream& out, const Queue& queue);

private:

// our array
Potion *items;
// our index positions
int front;
int back;
// our max queue size for this instance of Queue
int qSize;
// how many items are in the queue so far
int qCount; 

};

#endif