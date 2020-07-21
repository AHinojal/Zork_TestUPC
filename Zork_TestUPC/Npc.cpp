#include "Npc.h"

Npc::Npc(string name, string description, Room* location) : Creature(name, description, location)
{
	type = NPC;

}

Npc::~Npc()
{
}
