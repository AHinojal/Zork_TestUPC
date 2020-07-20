#include "Creature.h"

Creature::Creature(string name, string description) : Entity(name, description)
{
	type = CREATURE;
}

Creature::~Creature()
{
}

string Creature::getName()
{
	return name;
}

void Creature::setName(string newName)
{
	name = newName;
}
