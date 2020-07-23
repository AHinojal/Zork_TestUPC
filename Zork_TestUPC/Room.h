#pragma once
#include "Entity.h"
class Room : public Entity
{
	public:
		// Constructors & destructor
		Room(string name, string description);
		~Room();

		void showInfo();
};

