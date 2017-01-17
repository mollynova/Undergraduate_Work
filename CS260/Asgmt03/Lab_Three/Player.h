// enum type: gender: MALE, FEMALE, UNKNOWN

#ifndef PLAYER_H
#define PLAYER_H

#pragma once

enum Gender{UNKNOWN, MALE, FEMALE};

class Player
{
public:
// construtors

	Player();
	Player(char* name, Gender gender);
	Player(const Player& player);
	~Player();
	const Player& operator=(const Player& player);

	// member functions
	int GetLevel() { return level;}
	char* GetName() { return name; }
	void LevelUp();

private:
	char * name;
	int level;
	Gender gender;
};

#endif