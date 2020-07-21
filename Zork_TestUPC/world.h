#pragma once
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include "Npc.h"
#include "Exit.h"
#include <vector>

class World {
	public:
		vector<Item*> items;
		vector<Room*> rooms;
		vector<Exit*> exits;
		vector<Npc*> npcs;
		Player* player;

		World(); // Constructor por defecto
		~World(); // Destructor

		void showHelpComands();
		void showActualRoom();
		bool tryChangeRoom(string direction);
		bool takeItem(string nameItem);
		void showDialogNpc();

	private:
		Exit* getPossibleDestination(string direction);

};
