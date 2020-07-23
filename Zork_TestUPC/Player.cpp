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

// Method that when called shows the information of the player
void Player::showInfo()
{
	std::cout << name << " - " << description;
}

// Method that returns the player's current room
Room * Player::getLocation()
{
	return location;
}

// Method that returns the player's current inventory
vector<Item*> Player::getInventory()
{
	return this->inventory;
}

// Setter to change the player's location
void Player::setLocation(Room * newRoom)
{
	this->location = newRoom;
}

// Method that returns all the information of the player's current inventory
void Player::showInventary()
{
	std::cout << "[";
	for (int i = 0; i < this->inventory.size(); i++) {
		std::cout << this->inventory[i]->getName();
		// If you have items within the container item
		if (this->inventory[i]->getContains().size() > 0) {
			list<Entity*> contains = this->inventory[i]->getContains();
			list<Entity*>::iterator it;
			for (it = contains.begin(); it != contains.end(); it++)
			{
				Entity* item = *it;
				string objectName = item->getName();
				std::cout << "(" << objectName << ")";
			}
		}
		if (i < this->inventory.size()-1) {
			std::cout << ", ";
		}	
	}
	std::cout << "]";
	
}

// Method that when called, tries to see if it is possible to drop the object that is passed to us by command. Returns a boolean
bool Player::throwItem(string nameItem)
{
	bool result = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		// Only main items can be thrown away
		if (this->inventory[i]->getName() == nameItem) {
			this->inventory[i]->setIsAlreadyTaken(false);
			this->inventory.erase(this->inventory.begin() + i);
			result = true;
		} 
	}
	return result;
}
