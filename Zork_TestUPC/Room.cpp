#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(string name, string description) : Entity(name, description)
{
	type = ROOM;
}

Room::~Room()
{
}

void Room::showInfo()
{
	std::cout << "\n" << name << "\n";
	std::cout << "\n" << description << "\n";
}
