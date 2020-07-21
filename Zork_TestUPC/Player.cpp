#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, string description, Room* location) : Creature(name, description, location)
{
	type = PLAYER;
	this->inventory = {};
}

Player::~Player()
{
}

void Player::showInfo()
{
	std::cout << name << " - " << description;
}

Room * Player::getLocation()
{
	return location;
}

vector<Item*> Player::getInventory()
{
	return this->inventory;
}

void Player::setLocation(Room * newRoom)
{
	this->location = newRoom;
}

void Player::showInventary()
{
	std::cout << "[";
	for (int i = 0; i < this->inventory.size(); i++) {
		std::cout << this->inventory[i]->getName();
		if (i < this->inventory.size()-1) {
			std::cout << ", ";
		}	
	}
	std::cout << "]";
	
}

bool Player::throwItem(string nameItem)
{
	bool result = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		if (this->inventory[i]->getName() == nameItem) {
			this->inventory[i]->setIsAlreadyTaken(false);
			this->inventory.erase(this->inventory.begin() + i);
			result = true;
		}
	}
	return result;
}
