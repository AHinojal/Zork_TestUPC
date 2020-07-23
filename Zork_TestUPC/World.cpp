// World.cpp : This file contains everything relevant to the game's world.

#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Npc.h"
#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

World::World()
{
	// Initialize all game elements here
	// ROOMS
	Room* porch = new Room("PORCH", "You're in front of your front door. On your left is your neighbor Paco's house.\nTo get in, you need a key. Incidentally, you came out without them and you'll have to manage.\nIt's possible that the neighbor has a copy of them...");
	Room* neighbourHouse = new Room("NEIGHBOR'S HOUSE", "You're at the entrance of your neighbor Paco's house.\nHis wife is on the porch, sitting on a chair.\nTo your right, is your house.");
	Room* hall = new Room("HALL", "You're finally home! There's no light on and you hear a sound, but you don't know where it's coming from.\nIf you want to go back to the entrance, go south. You can also go to your left, which is your parents' room, or to the right, the kitchen.\nAlso, in front of you is your room.");
	Room* parentsBedroom = new Room("PARENTS' ROOM", "You find your mother already asleep and your father watching TV at a very high volume.\nThe sound you've heard in the hall could provide from here...\nIn front of you, you have the bathroom and to the east, you would return to the hall.");
	Room* playerBedroom = new Room("PLAYER'S ROOM", "The room's a mess. On the floor, you've got your backpack with the baseball stuff on it.\nIf you want to go back to the hall, go to the south. To the west, you have the bathroom.");
	Room* bathroom = new Room("BATHRROM", "The toilet is completely empty. There's nothing useful.\nYour parents' room is to the south and yours is to the west.");
	Room* kitchen = new Room("KITCHEN", "Your parents left dinner on your plate. Inexplicably, the knife is missing from the table.\nYou also notice the basement door is ajar. To get there, go to the south.\nIf you want to go back to the hall, head east. You can also go to the garden, which is in front of you.");
	Room* garden = new Room("GARDEN", "The door was a little open...\nIt's very quiet. There's rarely a burglary in the neighbourhood.\nBut you never know...\nGo back to the kitchen.");
	Room* basement = new Room("BASEMENT", "You go downstairs and, by surprise, you find a thief stealing.\nHe doesn't seem to have seen you. It's your turn to face him.");
	this->rooms.push_back(porch);
	this->rooms.push_back(neighbourHouse);
	this->rooms.push_back(hall);
	this->rooms.push_back(parentsBedroom);
	this->rooms.push_back(playerBedroom);
	this->rooms.push_back(bathroom);
	this->rooms.push_back(kitchen);
	this->rooms.push_back(garden);
	this->rooms.push_back(basement);

	// ITEMS
	Item* keysHouse = new Item("KEYS", "Luckily, the neighbors had a copy...", neighbourHouse);
	Item* dinner = new Item("DINNER", "You can tell that dinner was prepared hours ago, it's cold...", kitchen);
	Item* baseballBat = new Item("BAT", "Is old enough, but to protect me in an emergency, it's okay...", playerBedroom);
	Item* baseballGlove = new Item("GLOVE", "It's Dad's old glove. He's very fond of it, and yet he gave it to me...", playerBedroom);
	Item* baseballCap = new Item("CAP", "I bought this New York Yankees' cap when I went to see one of their games...", playerBedroom);
	this->items.push_back(keysHouse);
	this->items.push_back(dinner);
	list<Entity*> itemsBaseballBag = {};
	itemsBaseballBag.push_back(baseballBat);
	itemsBaseballBag.push_back(baseballGlove);
	itemsBaseballBag.push_back(baseballCap);
	Item* baseballBag = new Item("BAG", "Contains the following items in: BAT, GLOVE, CAP", itemsBaseballBag, playerBedroom);
	this->items.push_back(baseballBag);

	// MOVEMENTS / EXITS
	Exit* move1 = new Exit("NORTH", "", NORTH, porch, hall, true, keysHouse);
	Exit* move3 = new Exit("SOUTH", "", SOUTH, hall, porch, false, NULL);
	Exit* move2 = new Exit("WEST", "", WEST, porch, neighbourHouse, false, NULL);
	Exit* move4 = new Exit("EAST", "", EAST, neighbourHouse, porch, false, NULL);
	Exit* move5 = new Exit("WEST", "", WEST, hall, parentsBedroom, false, NULL);
	Exit* move6 = new Exit("EAST", "", EAST, parentsBedroom, hall, false, NULL);
	Exit* move7 = new Exit("NORTH", "", NORTH, hall, playerBedroom, false, NULL);
	Exit* move8 = new Exit("SOUTH", "", SOUTH, playerBedroom, hall, false, NULL);
	Exit* move9 = new Exit("EAST", "", EAST, hall, kitchen, false, NULL);
	Exit* move10 = new Exit("WEST", "", WEST, kitchen, hall, false, NULL);
	Exit* move11 = new Exit("NORTH", "", NORTH, parentsBedroom, bathroom, false, NULL);
	Exit* move12 = new Exit("SOUTH", "", SOUTH, bathroom, parentsBedroom, false, NULL);
	Exit* move13 = new Exit("EAST", "", EAST, bathroom, playerBedroom, false, NULL);
	Exit* move14 = new Exit("WEST", "", WEST, playerBedroom, bathroom, false, NULL);
	Exit* move15 = new Exit("SOUTH", "", SOUTH, garden, kitchen, false, NULL);
	Exit* move16 = new Exit("NORTH", "", NORTH, kitchen, garden, false, NULL);
	Exit* move17 = new Exit("SOUTH", "", SOUTH, kitchen, basement, false, NULL);
	this->exits.push_back(move1);
	this->exits.push_back(move2);
	this->exits.push_back(move3);
	this->exits.push_back(move4);
	this->exits.push_back(move5);
	this->exits.push_back(move6);
	this->exits.push_back(move7);
	this->exits.push_back(move8);
	this->exits.push_back(move9);
	this->exits.push_back(move10);
	this->exits.push_back(move11);
	this->exits.push_back(move12);
	this->exits.push_back(move13);
	this->exits.push_back(move14);
	this->exits.push_back(move15);
	this->exits.push_back(move16);
	this->exits.push_back(move17);

	// CREATURES
	// NPCs
	Npc* neighbour = new Npc("LILY", "How tall you are, pretty boy! Here! Take your house keys!", neighbourHouse);
	Npc* dad = new Npc("DAD", "What are you doing up at this hour, son?", parentsBedroom);
	Npc* thief = new Npc("THIEF", "This shouldn't be happening...", basement);
	this->npcs.push_back(neighbour);
	this->npcs.push_back(dad);
	this->npcs.push_back(thief);
	// PLAYER
	string namePlayer;
	std::cout << "Give me your name, hero/heroin!\n" << ">";
	std::getline(std::cin, namePlayer);
	std::cout << "\n";
	// Set the player's name here
	this->player = new Player(namePlayer, "Let's start the adventure!", porch);
	std::cout << "Welcome, " << this->player->getName() << "! " << this->player->getDescription() << "\n\n";
	std::cout << "NOTE: If you want help, use the command HELP to open this menu." << "\n\n";
	this->player->getLocation()->showInfo();
	std::cout << "\n";
}

World::~World()
{
	// Destroy World
	items.clear();
	rooms.clear();
	exits.clear();
	npcs.clear();
}

// Method that when called, shows all the game commands
void World::showHelpComands()
{
	std::cout << "COMMANDS:" << "\n";
	std::cout << "- HELP" << " : " << "We opened the help menu." << "\n";
	std::cout << "- ROOM" << " : " << "The description of the current room where the player is located is displayed." << "\n";
	std::cout << "- TAKE" << " : " << "We keep items in inventory, if possible." << "\n";
	std::cout << "- DROP" << " : " << "We remove items from the inventory, if possible." << "\n";
	std::cout << "- MOVE [COORDENATE]" << " : " << "We indicate the player's movement. Type of coordinates: NORTH, SOUTH, EAST, WEST." << "\n";
	std::cout << "- TALK" << " : " << "We do interaction between NPC and player." << "\n";
	std::cout << "- ATTACK" << " : " << "It allows us to make an attack if the player has an object for it and if we can do it." << "\n";
	std::cout << "- INVENTORY" << " : " << "We see all the objects that the player has stored." << "\n";
	std::cout << "- CLEAR" << " : " << "We cleared the command terminal. We can consult all of the above, if we upload the scroll." << "\n";
	std::cout << "- QUIT" << " : " << "Salimos del juego." << "\n";
}

// Method that returns the player's current room
void World::showActualRoom()
{
	this->player->getLocation()->showInfo();
}

// Method that when called, tries to see if it is possible the change of room by the player. Return a Boolean
bool World::tryChangeRoom(string direction)
{
	bool isChangedRoom = false;
	Exit* move = getPossibleDestination(direction);
	if (move != NULL) {
		// We check if the room needs a key
		if (!move->getIsLocked()) {
			this->player->setLocation(move->getDestination());
			isChangedRoom = true;
		} else {
			// We're checking to see if we have the key in inventory
			vector<Item*> actualInventory = this->player->getInventory();
			for (int i = 0; i < actualInventory.size(); i++) {
				if (actualInventory[i]->getName() == move->getkeyDoor()->getName()) {
					this->player->setLocation(move->getDestination());
					isChangedRoom = true;
				}
			}
			// If not possible, we show this message
			if (!isChangedRoom) {
				std::cout << "CLOSED! You don't have the necessary object to go to the next room." << "\n";
			}
		}
	}
	return isChangedRoom;
}

// Method that when called, tries to see if it is possible to take the object that is passed to us by command. Returns a boolean
bool World::takeItem(string nameItem)
{
	bool result = false;
	string actualRoom = this->player->getLocation()->getName();
	for (int i = 0; i < items.size(); i++) {
		// First we check the name of the object we want
		if (nameItem == items[i]->getName()) {
			// Then we check if the player and the object are in the same room
			if (actualRoom == items[i]->getLocation()->getName()) {
				if (!items[i]->getIsAlreadyTaken()) {
					items[i]->setIsAlreadyTaken(true);
					this->player->inventory.push_back(items[i]);
					// We show message by taking the object
					items[i]->showInfo();
					result = true;
				}
			}
		}
	}
	return result;
}

// Method that when called, shows the dialogue that the NPC's character has
void World::showDialogNpc()
{
	// We check which room the user is in 
	string actualLocationPlayer = this->player->getLocation()->getName();
	// Default message
	string dialogText = "There's no one to talk to.";
	for (int i = 0; i < npcs.size(); i++) {
		// If there is a character with dialogue, we change the content of the variable with the NPC's message
		if (actualLocationPlayer == npcs[i]->getLocation()->getName()) {
			dialogText = npcs[i]->showDialog();
		}
	}
	std::cout << dialogText << "\n";
}

// Method that looks for a possible movement from the room the user is in with the address set in command. Returns the movement if it exists
Exit* World::getPossibleDestination(string direction)
{
	Exit* possibleDestination = NULL;
	string actualRoom = this->player->getLocation()->getName();
	// We see if there is any possible movement from the current room and in the direction you select
	for (int i = 0; i < this->exits.size(); i++) {
		if (exits[i]->getOrigin()->getName() == actualRoom && exits[i]->getName() == direction) {
			possibleDestination = exits[i];
		}
	}
	return possibleDestination;
}