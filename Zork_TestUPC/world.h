#pragma once
#include "Room.h"

class World {
	public:
		Room* actualRoom;

		World(); // Constructor por defecto
		~World(); // Destructor

		void startGame();
		void showHelpComands();
		void showActualRoom();
};
