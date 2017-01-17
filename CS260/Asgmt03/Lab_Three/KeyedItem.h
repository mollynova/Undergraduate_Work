#ifndef KEYEDITEM_H
#define KEYEDITEM_H

typedef char* KeyType;

class KeyedItem
{
public: 
	KeyedItem();
	KeyedItem(const KeyType& keyValue);
	KeyType getKey() const;

	KeyType getSearchKey() { return searchKey; }
	
private:
	KeyType searchKey;
};

#endif
