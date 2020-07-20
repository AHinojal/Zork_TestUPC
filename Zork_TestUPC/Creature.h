#pragma once
#include "Entity.h"

class Creature : public Entity
{
	public:
		Creature(string name, string description);
		~Creature();

		string getName();
		void setName(string newName);
};

