#include "Item.h"
#include <iostream>

Item::Item(string name, string description, Room * location) : Entity (name, description)
{
	type = ITEM;
	this->location = location;
}

Item::~Item()
{
}

string Item::getName()
{
	return name;
}

Room* Item::getLocation()
{
	return this->location;
}

void Item::setLocation(Room* location)
{
	this->location = location;
}

void Item::showInfo()
{
	std::cout << name << " - " << description << "\n";
}
