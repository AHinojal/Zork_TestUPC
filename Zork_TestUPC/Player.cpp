#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, string description, Room* location) : Creature(name, description, location)
{
	type = PLAYER;
	this->inventory = {};
	// PRUEBA INVENTARIO
	Item* keysHouse = new Item("LLAVES DE CASA", "Menos mal que el vecino tenia una copia...", NULL);
	Item* keysHousle = new Item("BOMBA", "Menos mal que el vecino tenia una copia...", NULL);
	this->inventory.push_back(keysHouse);
	this->inventory.push_back(keysHousle);
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
	std::cout << "[";
	for (int i = 0; i < this->inventory.size(); i++) {
		std::cout << this->inventory[i]->getName();
		if (i < this->inventory.size()-1) {
			std::cout << ", ";
		}
		
	}
	std::cout << "]";
	
}

bool Player::takeItem(string nameItem)
{
	return false;
}

bool Player::throwItem(string nameItem)
{
	std::cout << nameItem;
	bool result = false;
	for (int i = 0; i < this->inventory.size(); i++) {
		//std::cout << i << "-" <<  this->inventory[i]->getName();
		if (this->inventory[i]->getName() == nameItem) {
			this->inventory.erase(this->inventory.begin() + i);
			result = true;
		}
	}
	return result;
}
