#include "Npc.h"

Npc::Npc(string name, string description, Room* location) : Creature(name, description, location)
{
	type = NPC;

}

Npc::~Npc()
{
}

// Method that return a string with the NPC's dialog
string Npc::showDialog()
{
	return "*" + name + ": " + description;
}
