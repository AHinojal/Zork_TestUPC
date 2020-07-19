#include "world.h"

World::World()
{
}

World::World(int edad) {
	this->edad = edad;
}

World::~World()
{
}

int World::getEdad()
{
	return this->edad;
}

void World::setEdad(int edad)
{
	this->edad = edad;
}
