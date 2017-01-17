#include"Queue.h"
#include<iostream>
#include<assert.h>
#define NULL 0


Queue::Queue(int queueSize) :
qSize(queueSize),
front(0),
back(0),
qCount(0)
{
    items = new Potion[qSize];
}

Queue::~Queue()
{
	delete [] items;
}

Queue::Queue(const Queue& queue)
{
	qCount = queue.qCount;
	front = queue.front;
	back = queue.back;
	qSize = queue.qSize;

	items = new Potion[qSize];

	int iterator;
	while(items != NULL)
	{
		for(int i = queue.front, iterator = 0; iterator < queue.qCount; i = (i + 1) % queue.qSize, iterator++)
		{
			items[i] = queue.items[i];
		}
	}
}

bool Queue::enqueue(const Potion& potion)
{
	//Potion potion(potion);
	if(qCount == qSize)
	{
		return false;
	}	


	//if this is the very beginning{
		if(items[0].GetType() == UNKNOWN && items[1].GetType() == UNKNOWN && items[2].GetType() == UNKNOWN
			&& items[3].GetType() == UNKNOWN && items[4].GetType() == UNKNOWN){
			items[0] = potion;
			qCount++;
			return true;
		} else if(items[0].GetType() != UNKNOWN && items[1].GetType() == UNKNOWN && items[2].GetType() == UNKNOWN
			&& items[3].GetType() == UNKNOWN && items[4].GetType() == UNKNOWN){
				items[back + 1] = potion;
				back++;
				qCount++;
				return true;
		} else if(qCount < qSize){
		
			if (back < (qSize-1)){
				items[back + 1] = potion;
				back++;
			//(back/* + 1*/) % qSize; 
				qCount++;
			} else {
				items[(back + 1) % qSize] = potion;
				back = ((back+1) % qSize);
				qCount++;
			}
		return true;
	}
	
}

bool Queue::dequeue(Potion& potion)
{
	// if list is empty return false
	if(qCount == 0)
	{
		return false;
	}
	// if list is not empty
	else 
	{

		potion = items[front];
		front = (front + 1) % qSize;
		qCount--;
		
		return true;
	}
}

bool Queue::isEmpty()
{
	if(qCount == 0)
	{
		return true;
	}
	else {
		return false;
	}
	//return qSize == 0;
}

bool Queue::isFull()
{
	return qSize == qCount;
}

const Queue& Queue::operator=(const Queue& queue)
{
	if(this != &queue)
	{

		delete [] this->items;

		// now we need to change all the sizing parameters and pointers from QueueA to the
		// ones from QueueB so it all fits correctly
		
		this->qCount = queue.qCount;
		this->front = queue.front;
		this->back = queue.back;
		this->qSize = queue.qSize;
		
		// now we need to make a new array for QueueA using our QueueB info
		items = new Potion[qSize];

		// now we need to copy all the data from QueueB ino Queue A
		// shouldnt need to mod anything because we are just copying each item in the array
		// into the new array one by one, including the null ones
		for(int i = 0; i < queue.qSize; i++)
		{
			items[i] = queue.items[i];
		}

	}

		return * this;
}

bool Queue::getFront(Potion& potion) const
{
	if(qCount == 0)
	{
		return false;
	}

	else { 
		potion = items[front];
		return true;
	}
}