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
				else if (command == "LIMPIAR") {
					std::cout << "\n\n\n\n\n\n\n\n\n\n";
				}
				else if (command == "VER") {
					zorkWorld.showActualRoom();
				}
				else if (command == "QUIT") {
					exit(0);
				}
				else if (command == "DIALOGAR") {
					zorkWorld.showDialogNpc();
					if (zorkWorld.player->getLocation()->getName() == "SOTANO") {
						std::cout << "El ladron te ha herido de gravedad con el cuchillo robado. HAS PERDIDO! :(" << "\n";
						endGame = true;
					}
				}
				else if (command == "ATACAR") {
					if (zorkWorld.player->getLocation()->getName() == "SOTANO") {
						bool canAttack = false;
						vector<Item*> actualInventoryPlayer = zorkWorld.player->getInventory();
						for (int i = 0; i < actualInventoryPlayer.size(); i++) {
							if (actualInventoryPlayer[i]->getName() == "BATE") {
								canAttack = true;
							}
						}
						if (!canAttack) {
							zorkWorld.showDialogNpc();
						}
						string message = canAttack ? "Has conseguido detener al ladron! HAS GANADO! ENHORABUENA!" : "No tienes nada con que atacar y el ladron te ha herido...HAS PERDIDO! :(";
						std::cout << message << "\n";
						endGame = true;
					}
					else {
						std::cout << "No puedes usar este comando en estos momentos" << "\n";
					}
				}
				else if (command == "INVENTARIO") {
					std::cout << "Inventario del jugador: ";
					zorkWorld.player->showInventary();
					std::cout << "\n";
				}
				else if (command == "COGER") {
					std::cout << "Que objeto quieres coger?" << "\n\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					object = transformUpperCase(object);
					std::cout << "\n";
					// TODO: Tendremos que crear un metodo en el jugador compare si esta en la habitacion adecuada y lo que coge esta en la lista de items
					bool canTake = zorkWorld.takeItem(object);
					string message = (canTake) ? "Se ha metido en tu inventario." : "El objeto no esta en la habitacion o ya lo tienes en el inventario.";
					std::cout << message << "\n";
				}
				else if (command == "SOLTAR") {
					std::cout << "Que objeto quieres soltar?" << "\n\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					object = transformUpperCase(object);
					std::cout << "\n";
					// Tendremos que crear un metodo en el jugador mire su inventario y si tiene el objeto, eliminarlo de la lista
					bool canThrow = zorkWorld.player->throwItem(object);
					string message = (canThrow) ? "El objeto ha sido eliminado del inventario." : "No tienes ese objeto en el inventario.";
					std::cout << message << "\n";
				}
				else {
					std::cout << "Este comando no es valido." << "\n";
				}
				break;
			// Si son dos palabras -> direccion
			case 2:
				// Comprobamos si la entrada de dos palabras es la direccion que queremos ir
				goWord = command.substr(0, 2);
				direction = command.substr(3, command.length() - 1);

				if (goWord == "IR") {
					// Podemos ir a la direccion que queramos
					if (direction == "NORTE" || direction == "SUR" || direction == "ESTE" || direction == "OESTE") {
						// TODO: Habra que comprobar si la habitacion puede ir esa direccion
						bool changeRoom = zorkWorld.tryChangeRoom(direction);
						if (changeRoom) {
							zorkWorld.player->getLocation()->showInfo();
						}
						else {
							std::cout << "No puedes moverte en esa direccion" << "\n";
						}
					}
					else {
						std::cout << "Esta direccion no es valida." << "\n";
					}
				}
				else {
					std::cout << "Este comando no es valido." << "\n";
				}
				break;
			default:
				std::cout << "Este comando no es valido." << "\n";
				break;
		}

		std::cout << "\n";

		if (endGame) {
			canPlay = false;
		}
	}

	std::cout << "Thanks for playing Zork by Alvaro Hinojal, " << transformUpperCase(zorkWorld.player->getName()) << "!\n";
}