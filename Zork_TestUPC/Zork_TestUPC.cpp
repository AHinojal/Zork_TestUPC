// Zork_TestUPC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "world.h"

int main()
{
    std::cout << "Hello to Zork by Alvaro Hinojal!\n";

	World zorkWorld(30);
	std::cout << zorkWorld.getEdad() << "\n";
	zorkWorld.setEdad(40);
	std::cout << zorkWorld.getEdad() << "\n";


}