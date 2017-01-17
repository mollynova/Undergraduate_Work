#include "Skill.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>


Skill::Skill() : name(NULL), description(NULL), level(0)
{
}

Skill::Skill(char* name, char* description, int level) :
	name(NULL), description(NULL), level(0)
{
	setName(name);
	setDescription(description);
	setLevel(level);

	//(we may need some weird return true or return &this thing in here)
}

Skill::Skill(Skill& skill) :
	name(NULL), description(NULL), level(0)
{
	setName(skill.name);
	setDescription(skill.description);
	setLevel(skill.level);
	// again may need a return true or return&this thing based off the weirdness of the hash function assignment
}

Skill::~Skill()
{
	  if(name)
        delete [] name;
    if(description)
        delete [] description;
}

void Skill::Display(ostream& out)
{
	if(this->GetLevel() == 0)
	{
	cout << "    -" << this->GetName();
	
	cout << " -- " << this->GetDescription() << " [Lvl: " << this->GetLevel() << "]" << endl;
	}
	else if(this->GetLevel() == 1)
	{
	cout << "      -" << this->GetName() << " -- " << this->GetDescription() << " [Lvl: " << this->GetLevel() << "]" << endl;
	}
	else if(this->GetLevel() == 5)
	{
	cout << "        -" << this->GetName() << " -- " << this->GetDescription() << " [Lvl: " << this->GetLevel() << "]" << endl;
	}
	else if(this->GetLevel() == 10)
	{
	cout << "            -" << this->GetName() << " -- " << this->GetDescription() << " [Lvl: " << this->GetLevel() << "]" << endl;
	}
	else if(this->GetLevel() == 20)
	{
	cout << "              -" << this->GetName() << " -- " << this->GetDescription() << " [Lvl: " << this->GetLevel() << "]" << endl;
	}


}

void Skill::setName(char* name)
{
    if (this->name)
        delete [] this->name;

    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void Skill::setDescription(char* description)
{
    if (this->description)
        delete [] this->description;

    this->description = new char[strlen(description)+1];
    strcpy(this->description, description);
}

void Skill::setLevel(int level)
{
    this->level = level;
}

 Skill& Skill::operator=(Skill& aSkill)
 {
	setName(aSkill.name);
    setDescription(aSkill.description);
    setLevel(aSkill.level);

    return *this;
 }
    

ostream& operator<<(ostream& out, Skill& aSkill)
{
	cout << aSkill.name << endl;
    return out;
}