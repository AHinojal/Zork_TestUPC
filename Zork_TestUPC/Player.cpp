#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, string description, Room* location) : Creature(name, description, location)
{
	type = PLAYER;
	
}

Player::~Player()
{
}

void Player::showInfo()
{
	std::cout << name << " - " << description;
}
