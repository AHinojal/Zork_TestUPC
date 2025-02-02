#pragma once
#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include <vector>

enum DirectionType {
	NORTH, SOUTH, EAST, WEST
};
class Exit : public Entity
{
	public:
		DirectionType direction;
		Room* origin;
		Room* destination;
		bool isLocked;
		Item* keyDoor;

		// Constructors & destructor
		Exit(string name, string description, DirectionType direction, Room* origin, Room* destination, bool isLocked, Item* keyDoor);
		~Exit();

		Room* getOrigin();
		Room* getDestination();
		bool getIsLocked();
		Item* getkeyDoor();
};

