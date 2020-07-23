// Zork_TestUPC.cpp : This file contains the "main" function. The execution of the program starts and ends there.

#include <iostream>
#include <string>
#include "World.h"
#include "Zork_TestUPC.h"

using namespace std;

// Method used to transform all user input into uppercase letters
string transformUpperCase(string word) {
	for (int i = 0; i < word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}

// Method used to know the words that the command has, that is, to know if it is a simple command or a movement.
int accountantWordString(string sentence) {
	int wordsCont = 1;
	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == ' ' && sentence[i + 1] != ' ')
		{
			wordsCont++;
		}
	}
	return wordsCont;
}

int main()
{
    std::cout << " ===== Hello to Zork by Alvaro Hinojal! ===== " << "\n\n";

	// Initialization World
	World zorkWorld;
	// Game control variables
	bool canPlay = true;
	bool endGame = false;

	// While the game not ends, repeat this loop
	while (canPlay) {
		// Control Input User
		string command;
		std::cout << ">";
		std::getline(std::cin, command);
		std::cout << "\n";

		command = transformUpperCase(command);
		
		int wordsCont = accountantWordString(command);

		// We see what we do with the command
		string goWord;
		string direction;
		// We managed if the command is valid or is in the list -> If not, error message
		switch (wordsCont) {
			// ONW Word -> Command
			case 1:
				if (command == "HELP") {
					zorkWorld.showHelpComands();
				}
				else if (command == "CLEAR") {
					std::cout << "\n\n\n\n\n\n\n\n\n\n";
				}
				else if (command == "ROOM") {
					zorkWorld.showActualRoom();
				}
				else if (command == "QUIT") {
					exit(0);
				}
				else if (command == "TALK") {
					zorkWorld.showDialogNpc();
					// If player is in the basement and put this command -> LOSE
					if (zorkWorld.player->getLocation()->getName() == "BASEMENT") {
						std::cout << "The thief has seriously injured you with the stolen knife. YOU'VE LOST! :(" << "\n";
						endGame = true;
					}
				}
				else if (command == "ATTACK") {
					// If player is in the basement and put this command
					if (zorkWorld.player->getLocation()->getName() == "BASEMENT") {
						bool canAttack = false;
						// We look if th playes has the bag with the bat
						vector<Item*> actualInventoryPlayer = zorkWorld.player->getInventory();
						for (int i = 0; i < actualInventoryPlayer.size(); i++) {
							// If has the bag -> Player can attack and WIN
							if (actualInventoryPlayer[i]->getName() == "BAG") {
								canAttack = true;
							}
						}
						// If has not the bag -> Player LOSE
						if (!canAttack) {
							zorkWorld.showDialogNpc();
						}
						// Message depends to variable -> Ternary conditional operator
						string message = canAttack ? "You managed to stop the thief with the bat you had in your backpack! YOU'VE WON! CONGRATULATIONS!" : "You have nothing to attack with and the thief has hurt you...YOU HAVE LOST! :(";
						std::cout << message << "\n";
						endGame = true;
					}
					else {
						std::cout << "You can't use this command right now." << "\n";
					}
				}
				else if (command == "INVENTORY") {
					std::cout << "Player's Inventory: ";
					zorkWorld.player->showInventary();
					std::cout << "\n";
				}
				else if (command == "TAKE") {
					// We control the name of the item
					std::cout << "What item do you want to take?" << "\n\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					object = transformUpperCase(object);
					std::cout << "\n";
					// Call to a method in Player class that compares if you are in the right room and what you take is in the list of items
					bool canTake = zorkWorld.takeItem(object);
					string message = (canTake) ? "He's gotten into your inventory." : "The item is either not in the room or already in the inventory.";
					std::cout << message << "\n";
				}
				else if (command == "DROP") {
					std::cout << "What object do you want to drop?" << "\n\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					object = transformUpperCase(object);
					std::cout << "\n";
					// Call to a method in World class where the player looks at his inventory and if he has the item, removes it from the list
					bool canThrow = zorkWorld.player->throwItem(object);
					string message = (canThrow) ? "The item has been removed from inventory." : "You don't have that item in your inventory.";
					std::cout << message << "\n";
				}
				else {
					std::cout << "This command is invalid." << "\n";
				}
				break;
			// TWO words -> Movement
			case 2:
				// We check if the two - word entry is the direction we want to go
				goWord = command.substr(0, 4);
				direction = command.substr(5, command.length() - 1);

				if (goWord == "MOVE") {
					// We can go to any address we want.
					if (direction == "NORTH" || direction == "SOUTH" || direction == "EAST" || direction == "WEST") {
						// We check if the player can go that way
						bool changeRoom = zorkWorld.tryChangeRoom(direction);
						if (changeRoom) {
							zorkWorld.player->getLocation()->showInfo();
						}
						else {
							std::cout << "You can't move to that coordinate." << "\n";
						}
					}
					else {
						std::cout << "The input coordinate is not valid." << "\n";
					}
				}
				else {
					std::cout << "This command is invalid." << "\n";
				}
				break;
			default:
				std::cout << "This command is invalid." << "\n";
				break;
		}

		std::cout << "\n";

		// At the end of each loop, we look to see if the game is over in order to exit the loop on the next lap
		if (endGame) {
			canPlay = false;
		}
	}

	std::cout << "Thanks for playing Zork by Alvaro Hinojal, " << transformUpperCase(zorkWorld.player->getName()) << "!\n";
}