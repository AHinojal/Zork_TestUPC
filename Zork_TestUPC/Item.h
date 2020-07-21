#pragma once
#include "Entity.h"
#include "Room.h"

class Item : public Entity
{
	public:
		Room* location;
		Item(string name, string description, Room* location);
		~Item();

		string getName();
		Room* getLocation();
		void setLocation(Room* location);
		void showInfo();
};

