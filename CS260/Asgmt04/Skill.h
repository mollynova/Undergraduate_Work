#ifndef SKILL_H
#define SKILL_H
#include<iostream>

using namespace std;

class Skill
{
public:
	Skill();
	Skill(char* name, char* description, int level);
	Skill(Skill& skill);
	~Skill();
	void Display(ostream &out);
	void setName(char* name);
	void setDescription(char* description);
	void setLevel(int level);
	int GetLevel() { return level; }
	char* GetName() { return this->name; }
	char* GetDescription() { return description; }
	Skill& operator=(Skill& aSkill);
    friend ostream& operator<<(ostream& out, Skill& aSkill);

private:
	char* name;
	char* description;
	int level;
};

#endif