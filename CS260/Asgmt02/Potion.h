#ifndef POTION_H
#define POTION_H
#include"main.h"
#include<iostream>
using namespace std;

class Potion
{
	public:
	Potion();
	Potion(PotionType type);
	Potion(const Potion& potion);

	const Potion& operator=(const Potion& potion);
	friend ostream& operator<<(ostream& out, const Potion& potion);


	PotionType GetType() const;
	void SetType(PotionType type);

	private:
	PotionType type;
};

#endif