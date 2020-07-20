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

void Entity::showInfo()
{
	std::cout << "\n" << this->name << "\n";
	std::cout << "\n" << this->description << "\n";
}
