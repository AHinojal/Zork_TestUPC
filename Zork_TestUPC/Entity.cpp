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

// Getters & Setters
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

// Method that when called shows the information of the item when player take an object
// It's a virtual method, since in the daughter classes, we change their behavior
void Entity::showInfo()
{
	std::cout << "You've picked up the object " << this->name << "! *" << this->description << "*\n";
}
