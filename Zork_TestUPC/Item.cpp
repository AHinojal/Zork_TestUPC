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

void Item::showInfo()
{
	std::cout << name << " - " << description << "\n";
}
