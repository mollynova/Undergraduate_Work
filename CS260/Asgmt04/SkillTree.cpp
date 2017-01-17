#include "SkillTree.h"
#include "node.h"
#include<stdio.h>
#include<string.h>
#include<iostream>

SkillTree::SkillTree() : root(NULL), title(NULL)
{
}

SkillTree::SkillTree(char* treeTitle) : root(NULL)
{
	this->title = treeTitle;
}

SkillTree::~SkillTree()
{
}

void SkillTree::Display(ostream &out)
{
	cout << "Skill Tree: " << this->GetTitle() << endl;
	node* curr = this->getRoot();
	if(!root)
	{
		cout << "    EMPTY" << endl;
	}
	else
	{
		node* curr = this->getRoot();
		curr->getSkill().Display(cout);

		if(curr->left && curr->center)
		{

		curr->left->getSkill().Display(cout);
		if(curr->left->left){
			curr->left->left->getSkill().Display(cout);
		}


		}
	}
}

Skill* SkillTree::FindSkill(char* skill)
{

	return recurseFind(root, skill);
	
	// returns pointer to skill, if !found return NULL
}

bool SkillTree::AddSkill(char* skill, char* descrip, int level)
{
	// this function automatically assumes we're adding a new root to the tree
	// because it doesn't pass in a parent skill

	Skill thisSkill(skill, descrip, level);
	
	// if the tree already has a root, e.g. it's not empty
	if(root != NULL)
	{
		node* temp = root;
		root = new node(thisSkill);
		root->left = temp;
		temp = NULL;
		delete temp;
	}
	// if the tree doesn't have a root , e.g. it's empty
	if(root == NULL)
	{
		root = new node(thisSkill);
	}
	
	return true;
}


bool SkillTree::AddSkill(char* skill, char* descrip, int level, char* parentName)
{
	Skill thisSkill(skill, descrip, level);
	
	node* curr = root;
	node* previous = root;
	
	//recurseAdd(curr, previous, thisSkill, parentName);
	
	return recurseAdd(curr, previous, thisSkill, parentName);


}

bool SkillTree::recurseAdd(node* curr, node* previous, Skill& skill, char* parentName)
{
	//int depth = 0;
	
	node * cur = curr;
	//node * previous = cur;
		// if the parent matches the node we're looking at
		Skill thisSkill = cur->getSkill();
		char* currName = thisSkill.GetName();
		char* pName = parentName;

		int par = (strlen(parentName));
		int curname = (strlen(thisSkill.GetName()));

		if(par != curname || thisSkill.GetName()[1] != parentName[1]){
			goto SKIP;
		} else if(par == curname && thisSkill.GetName()[par] != parentName[par]){
				goto SKIP;
			}
		

		
		else {
		
		
		// if all pointers are in use
			if(cur->left != NULL && cur->right != NULL && cur->center != NULL)
			{ 
				cout << endl << "Can't add more than 3 children. Sorry." << endl;
				return true;
			}

			// if left pointer is free
			if(cur->left == NULL)
			{
				// point left pointer to new node
				cur->left = new node(skill);
				cur->left->prev = cur;
				// if the root is the parent of the new node, set the nodes prev pointer to root
				if(cur == root)
				{
					cur->left->prev = root;
					
				}
				return true;
				
			}
			else if(cur->center == NULL)
			{ 
				cur->center = new node(skill);
				cur->center->prev = cur;
		// if the root is the parent of the new node, set the nodes prev pointer to root
				if(cur == root)
				{
					cur->center->prev = root;
				}
				return true;
				
			}
			else 
			{
				cur->right = new node(skill);
				cur->right->prev = cur;
			// if the root is the parent of the new node, set the nodes prev pointer to root
				if(cur == root)
				{
					cur->right->prev = root;
				}
				return true;
			}
			return true;
		
		}
	// Body of function (all above is base case)
	
	SKIP:
	if(cur->left != NULL){
		if(cur->left->left == NULL){
		cur->left->prev = cur;
	}
	}
		
	if(cur->left != NULL && cur->left->getTouched() != 2){
		cur->incTouched();
		recurseAdd(cur->left, cur, skill, parentName);
	}



	if(cur->left == NULL){
		cur->incTouched();
		cur->incTouched();
		recurseAdd(cur->prev, cur, skill, parentName);
	}

	if(cur->left != NULL && cur->left->getTouched() == 2){

		if(cur->center != NULL && cur->center->getTouched() != 2){
			recurseAdd(cur->center, cur, skill, parentName);
		}
		else if(cur->right != NULL && cur->right->getTouched() != 2){
			recurseAdd(cur->right, cur, skill, parentName);
		}
		else {
			cur->incTouched();
			recurseAdd(cur->prev, cur, skill, parentName);
		}
	}
	return true;
}

Skill* SkillTree::recurseFind(node*& aNode, char* skill)
{
	/*	node* curr = aNode;
		if(skill == curr->getSkill().GetName())
		{
			return &curr->getSkill();
		}
			
	// here's where we do alllll our recursion

	if(curr->left && curr->getTouched() == 0)
	{
		curr->incTouched();
		curr->left->prev = *&curr;
		curr = curr->left;
		recurseFind(curr, skill);
	}

	if(curr->center && curr->getTouched() == 0)
	{
		curr->incTouched();
		curr->center->prev = *&curr;
		curr = curr->center;
		recurseFind(curr, skill);
	}
	if(curr->right && curr->getTouched() == 0)
	{
		curr->incTouched();
		curr->right->prev = *&curr;
		curr = curr->right;
		recurseFind(curr, skill);
	}

	while(curr != NULL)
	{
		while(!curr->otherUntouchedChildren(curr, curr->prev))
		{
			curr->prev->incTouched();
			curr = curr->prev;
		}
		curr = curr->prev;
		curr->prev->incTouched();
	}
	
	if(curr->center && curr->getTouched() == 2)
	{
		curr->center->prev = *&curr;
		recurseFind(curr->center, skill);
	}
	
	if(curr->center && curr->getTouched() == 0)
	{
		curr->incTouched();
		curr->center->prev = *&curr;
		recurseFind(curr->center, skill);
	}
	return NULL;*/
	return 0;
}
