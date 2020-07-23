// Zork_TestUPC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include "world.h"
#include "Zork_TestUPC.h"

using namespace std;

string transformUpperCase(string word) {
	for (int i = 0; i < word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}

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

	World zorkWorld;
	bool canPlay = true;
	bool endGame = false;

	while (canPlay) {
		string command;
		std::cout << ">";
		std::getline(std::cin, command);
		std::cout << "\n";

		// Ponemos el comando en mayuscular
		command = transformUpperCase(command);
		
		// Contamos las palabras del comando
		int wordsCont = accountantWordString(command);

		// Vemos que hacemos con el comando
		string goWord;
		string direction;
		switch (wordsCont) {
			// Si es de una palabra -> comando
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
					if (zorkWorld.player->getLocation()->getName() == "BASEMENT") {
						std::cout << "The thief has seriously injured you with the stolen knife. YOU'VE LOST! :(" << "\n";
						endGame = true;
					}
				}
				else if (command == "ATTACK") {
					if (zorkWorld.player->getLocation()->getName() == "BASEMENT") {
						bool canAttack = false;
						vector<Item*> actualInventoryPlayer = zorkWorld.player->getInventory();
						for (int i = 0; i < actualInventoryPlayer.size(); i++) {
							if (actualInventoryPlayer[i]->getName() == "BAG") {
								canAttack = true;
							}
						}
						if (!canAttack) {
							zorkWorld.showDialogNpc();
						}
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
					std::cout << "What item do you want to take?" << "\n\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					object = transformUpperCase(object);
					std::cout << "\n";
					// TODO: Tendremos que crear un metodo en el jugador compare si esta en la habitacion adecuada y lo que coge esta en la lista de items
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
					// Tendremos que crear un metodo en el jugador mire su inventario y si tiene el objeto, eliminarlo de la lista
					bool canThrow = zorkWorld.player->throwItem(object);
					string message = (canThrow) ? "The item has been removed from inventory." : "You don't have that item in your inventory.";
					std::cout << message << "\n";
				}
				else {
					std::cout << "This command is invalid." << "\n";
				}
				break;
			// Si son dos palabras -> direccion
			case 2:
				// Comprobamos si la entrada de dos palabras es la direccion que queremos ir
				goWord = command.substr(0, 4);
				direction = command.substr(5, command.length() - 1);

				if (goWord == "MOVE") {
					// Podemos ir a la direccion que queramos
					if (direction == "NORTH" || direction == "SOUTH" || direction == "EAST" || direction == "WEST") {
						// TODO: Habra que comprobar si la habitacion puede ir esa direccion
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

		if (endGame) {
			canPlay = false;
		}
	}

	std::cout << "Thanks for playing Zork by Alvaro Hinojal, " << transformUpperCase(zorkWorld.player->getName()) << "!\n";
}