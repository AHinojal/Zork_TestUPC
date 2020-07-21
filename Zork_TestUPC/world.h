#pragma once
#include "Room.h"
#include "Player.h"

class World {
	public:
		Room* actualRoom;
		Player* player;

		World(); // Constructor por defecto
		~World(); // Destructor

		void startGame();
		void showHelpComands();
		void showActualRoom();
};
