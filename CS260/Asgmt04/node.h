#ifndef NODE_H
#define NODE_H

#include<iostream>
#include"Skill.h"
using namespace std;

class node
{
public:
	node();
	node(Skill& aSkill);
	Skill getSkill() { return skill; }
	void incHasLeft() { hasLeft = 1; }
	void incHasCenter() { hasCenter = 1; }
	void incHasRight() { hasRight = 1; }
	void incTouched() { touched++; }
	int getTouched() { return touched; }
	void resetTouched() { touched = 0; }
	
//private:
	//Skill* skill;
	node* left;
	node* right;
	node* center;
	node* prev;

private:
	Skill skill;
	int hasLeft;
	int hasCenter;
	int hasRight;
	int touched;
};

#endif