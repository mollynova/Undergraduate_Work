#include<stdlib.h>
#include"Potion.h"
#include"main.h"

Potion::Potion() :
type(UNKNOWN)
{
	
}

Potion::Potion(PotionType type)
{
	SetType(type);
}

Potion::Potion(const Potion& potion)
{
	type = potion.type;
}

PotionType Potion::GetType() const
{
	return type;
}

void Potion::SetType(PotionType type)
{
	this->type = type;
}

const Potion& Potion::operator=(const Potion& potion)
{
	// If the two objects are not already the same
	if(this != &potion)
	{
		// make object A the same as object B
		this->type = potion.type;
		
		return * this;
	}
	else 
	{
		return * this;
	}
	
}

ostream& operator<<(ostream& out, const Potion& potion)
{
	out << "Potion of " << PotionTypeString(potion.type) << endl;
	return out;
}

