#include "Entity.h"
#include <iostream>

Entity::Entity(string name, string description, list<Entity*> contains)
{
	this->type = ENTITY;
	this->name = name;
	this->description = description;
	this->contains = contains;
}

Entity::Entity(string name, string description)
{
	this->name = name;
	this->description = description;

}

string Entity::getName()
{
	return this->name;
}

void Entity::setName(string name)
{
	this->name = name;
}

string Entity::getDescription()
{
	return this->description;
}

list<Entity*> Entity::getContains()
{
	return this->contains;
}

void Entity::setDescription(string description)
{
	this->description = description;
}

void Entity::showInfo()
{
	std::cout << "You've picked up the object " << this->name << "! *" << this->description << "*\n";
}
