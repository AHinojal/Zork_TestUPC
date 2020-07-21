#pragma once
#include "Room.h"
#include "Player.h"
#include <vector>

class World {
	public:
		vector<Entity*> entities;
		Room* actualRoom;
		Player* player;

		World(); // Constructor por defecto
		~World(); // Destructor

		void showHelpComands();
		void showActualRoom();
};
