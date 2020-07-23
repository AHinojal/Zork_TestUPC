#include "Item.h"
#include <iostream>

Item::Item(string name, string description, Room * location) : Entity (name, description)
{
	type = ITEM;
	this->location = location;
	this->isAlreadyTaken = false;
}


Item::Item(string name, string description, list<Entity*> contains, Room * location) : Entity(name, description, contains)
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
	std::cout << "You've picked up the object " << name << "! *" << description << "*\n";
	if (contains.size() > 0) {
		std::cout << "Contains inside:" << "\n";
		list<Entity*>::iterator it;
		for (it = contains.begin(); it != contains.end(); it++)
		{
			Entity* item = *it;
			item->showInfo();
		}
		std::cout << "*NOTE*: Objects within an item may NOT be thrown away. You have to throw away the container object!" << "\n";
	}
}
