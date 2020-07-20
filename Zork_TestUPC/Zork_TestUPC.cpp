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

	zorkWorld.startGame();

	while (true) {
		string command;
		std::cout << ">";
		std::cin >> command;

		if (command == "HELP") {
			zorkWorld.showHelpComands();
		}
		else if (command == "VER") {
			zorkWorld.showActualRoom();
		}
		else if (command == "QUIT") {
			exit(0);
		}
		else {
			std::cout << command << "\n";
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