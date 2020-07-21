#include "Exit.h"

Exit::Exit(string name, string description, DirectionType direction, Room* origin, Room* destination, bool isLocked, Item* keyDoor) : Entity(name, description)
{
	this->direction = direction;
	this->origin = origin;
	this->destination = destination;
	this->isLocked = isLocked;
	this->keyDoor = keyDoor;
}

Exit::~Exit()
{
}

Room * Exit::getOrigin()
{
	return this->origin;
}

Room * Exit::getDestination()
{
	return this->destination;
}

bool Exit::getIsLocked()
{
	return this->isLocked;
}

Item * Exit::getkeyDoor()
{
	return this->keyDoor;
}
