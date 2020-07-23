#pragma once
#include "Creature.h"
class Npc : public Creature
{
	public: 
		// Constructors & destructor
		Npc(string name, string description, Room* location);
		~Npc();

		string showDialog();
};

