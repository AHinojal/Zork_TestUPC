#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Npc.h"
#include <string>
#include <iostream>

using namespace std;

World::World()
{
	// TODO: Inicializar todos los elementos de la partida aqui
	// HABITACIONES
	Room* porch = new Room("PORCHE", "Estas en la entrada de la casa. A tu izquierda esta la casa de tu vecino Paco.\nPara entrar necesitas unas llaves. Casualmente saliste sin ellas y tendras que arreglartelas.\nEs posible que el vecino tenga una copia de ellas...\n");
	Room* neighbourHouse = new Room("ENTRADA DE LA CASA DEL VECINO", "Estas en la entrada de la casa de tu vecino Paco.\nSu mujer se encuentra en el porche, sentada en una silla.\nA tu derecha, se encuentra tu casa.\n");
	Room* hall = new Room("SALON", "Por fin estas en casa!! No hay ninguna luz encendida y escuchas un sonido, pero no sabes de donde proviene.\nSi quieres volver a la entrada, esta al sur. Puedes dirigirte tambien a tu izquierda, que esta la habitacion de tus padres o a la derecha, la cocina.\nAdemas, delante tuya tienes tu habitacion.\n");
	Room* parentsBedroom = new Room("HABITACION DE TUS PADRES", "Te encuentras a tu madre ya dormida y a tu padre viendo la tele a un volumen altisimo.\nEl sonido que has escuchado en el salon podria proveenir de aqui.\nDebajo tienes el aseo y al oeste, volverias al salon.\n");
	Room* playerBedroom = new Room("HABITACION DEL JUGADOR", "La habitacion esta hecha un desastre. Encima de la cama tienes los libros de clase y en el suelo, tienes tirada la mochila con el material de beisbol.\nSi quieres volver a la entrada, esta al sur. Al este, tienes el aseo.\n");
	Room* bathroom = new Room("ASEO", "El aseo esta completamente vacio. No hay nada de utilidad.\nLa habitacion de tus padres la tienes al sur y la tuya, al oeste.");
	Room* kitchen = new Room("COCINA", "Tus padres te han dejado la cena preparada en el plato. Inexplicablemente, te falta el cuchillo en la mesa.\nTambien te das cuenta que la puerta del sotano esta entreabierta. Para ir ahi, ve al sur.\nSi quieres volver al salon, dirigete hacia el oeste. Tambien puedes dirigirte a la terraza, la cual tienes enfrente.");
	Room* garden = new Room("JARDIN", "Esta todo muy tranquilo. Rara vez hay robos en el vecindario.\nPero nunca se sabe...\nVuelve atras para regresar a la cocina.\n");
	Room* basement = new Room("SOTANO", "Bajas las escaleras y por sorpresa, te encuentras a un ladron robando.\nParece que no te ha visto. Te toca enfrentarte a el.\n");
	// MOVIMIENTOS

	// ITEMS

	// PERSONAJES
	// NPCs
	Npc* neighbour = new Npc("Lola", "neighbour", neighbourHouse);
	Npc* dad = new Npc("John", "dad", parentsBedroom);
	Npc* thief = new Npc("Thief", "Final boss", basement);
	// PLAYER
	string namePlayer;
	std::cout << "Give me your name, hero!\n" << ">";
	std::getline(std::cin, namePlayer);
	std::cout << "Welcome, " << namePlayer << "! Let's start the adventure!\n";
	// TODO: Setear el nombre del jugador aqui;
	this->player = new Player(namePlayer, "Let's start the adventure!", porch);
	this->actualRoom = this->player->getLocation();
	this->actualRoom->showInfo();
}

World::~World()
{

}

void World::showHelpComands()
{
	std::cout << "COMANDOS:" << "\n";
	std::cout << "- VER" << " : " << "Sale la descripcion de la sala" << "\n";
	std::cout << "- COGER" << " : " << "Guardamos item en el inventario" << "\n";
	std::cout << "- SOLTAR" << " : " << "Eliminamos item del inventario" << "\n";
	std::cout << "- IR [COORDENADA]" << " : " << "Movimiento del jugador. Tipo de coordenadas: NORTE, SUR, ESTE, OESTE" << "\n";
	std::cout << "- DIALOGAR" << " : " << "Interaccion entre NPC y jugador" << "\n";
	std::cout << "- INVENTARIO" << " : " << "Vemos los objetos que tiene el jugador" << "\n";
	std::cout << "- QUIT" << " : " << "Salimos del juego" << "\n";
	std::cout << "- HELP" << " : " << "Nos sale el menu de ayuda" << "\n";

}

void World::showActualRoom()
{
	this->actualRoom->showInfo();
}
