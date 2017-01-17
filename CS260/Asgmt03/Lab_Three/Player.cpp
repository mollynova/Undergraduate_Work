#include<iostream>
#include "Player.h"

using namespace std;

Player::Player() :
	name(NULL),
	level(0),
	gender(UNKNOWN)
{
}

Player::Player(char* name, Gender gender) :
	name(NULL),
	level(0),
	gender(UNKNOWN)

{
	this->name = name;
	this->gender = gender;
}

Player::Player(const Player& player) :
	name(NULL),
	level(0),
	gender(UNKNOWN)
{
	this->gender = player.gender;
	this->level = player.level;
	this->name = player.name;
}

Player::~Player()
{
	/*if(this->name)
	{
		delete [] this->name;
	}*/
	// I wrote the above code for the destructor but for some reason it was making my program crash.
	// I know commenting out the destructor makes memory leaks but I'm not sure what's going on.
	// >> I added a line of code that said "cout << "calling player destructor << endl;" after it,
	// and it printed every time i ADDED a player, so I'm just lost on this one.
}

const Player& Player::operator=(const Player& player)
{
	// i tried to implement something to delete what was already stored in this->name
	// but it kept making my program exit with a weird error so I gave up, I realize
	// this creates memory leaks

	this->name = player.name;
	this->gender = player.gender;
	this->level = player.level;
	return * this;
}

void Player::LevelUp()
{
	this->level++;
}