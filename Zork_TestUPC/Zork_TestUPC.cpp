// Zork_TestUPC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include "world.h"
#include "Zork_TestUPC.h"

using namespace std;

int main()
{
    std::cout << "Hello to Zork by Alvaro Hinojal!\n";

	World zorkWorld;

	while (true) {
		string command;
		std::cout << ">";
		std::getline(std::cin, command);

		// Pasen lo que nos pasen, siempre lo tendremos en mayusculas
		for (int i = 0; i < command.length(); i++) {
			command[i] = toupper(command[i]);
		}
		
		// Contamos las palabras
		int wordsCont = 1;
		for (int i = 0; i < command.length(); i++)
		{
			if (command[i] == ' ' && command[i + 1] != ' ')
			{
				wordsCont++;
			}
		}
		// Vemos que hacemos con el comando
		string goWord;
		string direction;
		switch (wordsCont) {
			case 1:
				if (command == "HELP") {
					zorkWorld.showHelpComands();
				}
				else if (command == "VER") {
					zorkWorld.showActualRoom();
				}
				else if (command == "QUIT") {
					exit(0);
				}
				else if (command == "INVENTARIO") {
					// TODO: Tendremos que crear un metodo en el jugador viendo el inventario que tiene
					std::cout << "Inventario del jugador: ";
					zorkWorld.player->showInfo();
					std::cout << "\n";

				}
				else if (command == "COGER") {
					std::cout << "Que objeto quieres coger?" << "\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					std::cout << object << "\n";
				}
				else if (command == "SOLTAR") {
					std::cout << "Que objeto quieres soltar?" << "\n";
					string object;
					std::cout << ">";
					std::getline(std::cin, object);
					std::cout << object << "\n";
				}
				else {
					std::cout << "Este comando no es valido." << "\n";
				}
				break;
			case 2:
				// Comprobamos si la entrada de dos palabras es la direccion que queremos ir
				goWord = command.substr(0, 2);
				direction = command.substr(3, command.length() - 1);

				if (goWord == "IR") {
					// Podemos ir a la direccion que queramos
					if (direction == "NORTE") {
						// TODO: Habra que comprobar si la habitacion puede ir esa direccion
						std::cout << "Vamos hacia adelante" << "\n";
					}
					else if (direction == "SUR") {
						std::cout << "Vamos hacia detras." << "\n";
					}
					else if (direction == "ESTE") {
						std::cout << "Vamos hacia la izquierda" << "\n";
					}
					else if (direction == "OESTE") {
						std::cout << "Vamos hacia la derecha." << "\n";
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
	}

	// RECUERDOS
	/*int numero = 10;
	int* ptr = &numero;
	std::cout << *ptr << "\n";
	std::cout << zorkWorld.getEdad() << "\n";
	zorkWorld.setEdad(40);
	std::cout << zorkWorld.getEdad() << "\n";

	std::cout << "Por favor ingrese su edad:" << "\n" << ">";
	int newAge;
	std::cin >> newAge;
	zorkWorld.setEdad(newAge);
	std::cout << zorkWorld.getEdad() << "\n";*/
}