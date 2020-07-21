#pragma once
#include "Creature.h"
#include <vector>
//#include "Item.h"

class Player : public Creature
{
	public:
		//vector<Item*> inventory;

		Player(string name, string description, Room* location);
		~Player();

		void showInfo();
		//void showInventary();
};

