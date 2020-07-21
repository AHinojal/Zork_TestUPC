#pragma once
#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
	public:
		Room* location;

		Creature(string name, string description, Room* location);
		~Creature();

		string getName();
		void setName(string newName);
		Room* getLocation();
		void setLocation(Room* location);
};

