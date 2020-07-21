#pragma once
#include "Creature.h"
#include "Item.h"
#include <vector>

class Player : public Creature
{
	public:
		vector<Item*> inventory;

		Player(string name, string description, Room* location);
		~Player();

		void showInfo();
		Room* getLocation();
		vector<Item*> getInventory();
		void setLocation(Room* newRoom);
		void showInventary();
		bool throwItem(string nameItem);
};

