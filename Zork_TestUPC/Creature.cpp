#include "Creature.h"

Creature::Creature(string name, string description, Room* location) : Entity(name, description)
{
	type = CREATURE;
	this->location = location;
}

Creature::~Creature()
{
}

Room* Creature::getLocation()
{
	return this->location;
}

void Creature::setLocation(Room* location)
{
	this->location = location;
}
