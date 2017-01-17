#include<iostream>
#include"node.h"

node::node() : skill(), left(NULL), center(NULL), right(NULL), prev(NULL), hasLeft(0), hasCenter(0), hasRight(0), touched(0)
{
	
}

node::node(Skill& aSkill) :
	hasLeft(0),
	hasCenter(0),
	hasRight(0),
	touched(0),
	skill(aSkill)

{
	this->left = NULL;
	this->right = NULL;
	this->center = NULL;
	this->prev = NULL;
}

