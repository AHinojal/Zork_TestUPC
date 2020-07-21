#pragma once
#include "Creature.h"
class Npc : public Creature
{
	public: 
		Npc(string name, string description, Room* location);
		~Npc();
};

