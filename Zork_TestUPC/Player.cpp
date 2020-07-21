#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, string description, Room* location) : Creature(name, description, location)
{
	type = PLAYER;
	this->inventory;
}

Player::~Player()
{
}

void Player::showInfo()
{
	std::cout << name << " - " << description;
}

void Player::showInventary()
{
	std::cout << "[ ";
	for (int i = 0; i < this->inventory.size(); i++) {
		this->inventory[i]->getName();
		std::cout << " ";
	}
	std::cout << "]";
	
}

bool Player::takeItem(string nameItem)
{
	return false;
}

bool Player::throwItem(string nameItem)
{
	bool result = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i]->getName() == nameItem) {
			// TODO: Ver como borrar el elemento del vector this->inventory[i].
			//this->inventory.
			result = true;
		}
	}
	return result;
}
