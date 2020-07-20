#include "world.h"
#include "room.h"
#include <string>
#include <iostream>

using namespace std;

World::World()
{
	// TODO: Inicializar todos los elementos de la partida aqui
	// HABITACIONES
	Room* entrada = new Room("PORCHE", "Estas en la entrada de la casa. A tu izquierda esta la casa de tu vecino Paco.\nPara entrar necesitas unas llaves. Casualmente saliste sin ellas y tendras que arreglartelas.\nEs posible que el vecino tenga una copia de ellas...\n");
	this->actualRoom = entrada;
	// MOVIMIENTOS

	// ITEMS

	// PERSONAJES
	// JUGADOR

	// NPCs

}

World::~World()
{
}

void World::startGame()
{
	string namePlayer;
	std::cout << "Give me your name, hero!\n" << ">";
	std::cin >> namePlayer;
	std::cout << "Welcome, " << namePlayer << "! Let's start the adventure!\n";
	// TODO: Setear el nombre del jugador aqui;
	this->actualRoom->showInfo();
}

void World::showHelpComands()
{
	std::cout << "COMMANDS:" << "\n";
	std::cout << "- VER" << " : " << "Sale la descripcion de la sala" << "\n";
	std::cout << "- OBSERVAR" << " : " << "Interaccionamos con objetos de la sasa" << "\n";
	std::cout << "- COGER" << " : " << "Guardamos item en el inventario" << "\n";
	std::cout << "- SOLTAR" << " : " << "Eliminamos item del inventario" << "\n";
	std::cout << "- IR [COORDENADA]" << "  :" << "Movimiento del jugador. Tipo de coordenadas: NORTE, SUR, ESTE, OESTE" << "\n";
	std::cout << "- DIALOGAR" << " : " << "Interacción entre NPC y jugador" << "\n";
}

void World::showActualRoom()
{
	this->actualRoom->showInfo();
}
