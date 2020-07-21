#pragma once
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include <vector>

class World {
	public:
		vector<Item*> items;
		vector<Room*> rooms;
		Room* actualRoom;
		Player* player;

		World(); // Constructor por defecto
		~World(); // Destructor

		void showHelpComands();
		void showActualRoom();
		bool takeItem(string nameItem);
};
