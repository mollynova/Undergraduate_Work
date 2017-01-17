#ifndef SKILLTREE_H
#define SKILLTREE_H
#include<iostream>
#include "Skill.h"
#include"node.h"

using namespace std; 

class SkillTree
{
public:
	SkillTree();
	SkillTree(char* treeTitle);
	~SkillTree();

	void Display(ostream &out);
	bool AddSkill(char* skill, char* descrip, int level);
	bool AddSkill(char* skill, char* descrip, int level, char* parentName);
	Skill* FindSkill(char* skill);
	char* GetTitle() { return title; }
	bool recurseAdd(node* curr, node* previous, Skill& skill, char* parentName);
	node* getRoot() { return root; }
	Skill* recurseFind(node*& aNode, char* skill);


private:
	//ostream m_out
	const static int MAX_CHILDREN = 3;

	char* title;
	node* root;
	// int entries;
};

#endif