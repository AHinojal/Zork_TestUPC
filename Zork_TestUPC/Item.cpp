#include "Item.h"
#include <iostream>

Item::Item(string name, string description, Room * location) : Entity (name, description)
{
	type = ITEM;
	this->location = location;
	this->isAlreadyTaken = false;
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

bool Item::getIsAlreadyTaken()
{
	return this->isAlreadyTaken;
}

void Item::setIsAlreadyTaken(bool isTaken)
{
	this->isAlreadyTaken = isTaken;
}

void Item::showInfo()
{
	std::cout << "Has recogido el objeto " << name << "! *" << description << "*\n";
}
