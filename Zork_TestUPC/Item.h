#pragma once
#include "Entity.h"
#include "Room.h"

class Item : public Entity
{
	public:
		Room* location;
		bool isAlreadyTaken;

		Item(string name, string description, Room* location);
		Item(string name, string description, list<Entity*> contains, Room* location);
		~Item();

		string getName();
		Room* getLocation();
		void setLocation(Room* location);
		bool getIsAlreadyTaken();
		void setIsAlreadyTaken(bool isTaken);
		void showInfo();
};

