#pragma once
#include <string>
#include <list>

using namespace std;

enum EntityType {
	ENTITY,
	CREATURE, NPC, PLAYER,
	EXIT,
	ROOM,
	ITEM
};
class Entity
{
	public:
		EntityType type;
		string name;
		string description;
		list<Entity*> contains;

		Entity(string name, string description, list<Entity*> contains);
		Entity(string name, string description);

		void showInfo();
};

