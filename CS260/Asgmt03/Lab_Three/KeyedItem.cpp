#include "KeyedItem.h"
#include <iostream>

KeyedItem::KeyedItem()
{
}

KeyedItem::KeyedItem(const KeyType& keyValue) :
	searchKey(keyValue) // initializing searchKey to keyValue
		// to be honest , i found something similar to this whole KeyedItem thing in the book and it works but I'm not sure
		// I completely understand how
{
}

KeyType KeyedItem::getKey() const 
{
	return searchKey;
}
	
