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
		void showInventary();
		bool takeItem(string nameItem);
		bool throwItem(string nameItem);
};

