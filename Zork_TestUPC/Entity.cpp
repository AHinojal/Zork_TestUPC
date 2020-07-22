#include "Entity.h"
#include <iostream>

Entity::Entity(string name, string description, list<Entity*> contains)
{
	this->type = ENTITY;
	this->name = name;
	this->description = description;

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

void Entity::setDescription(string description)
{
	this->description = description;
}

void Entity::showInfo()
{
	std::cout << this->name << "\n";
	std::cout << "\n" << this->description << "\n";
}
