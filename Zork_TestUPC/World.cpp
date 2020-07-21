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
	this->rooms.push_back(porch);
	this->rooms.push_back(neighbourHouse);
	this->rooms.push_back(hall);
	this->rooms.push_back(parentsBedroom);
	this->rooms.push_back(playerBedroom);
	this->rooms.push_back(bathroom);
	this->rooms.push_back(kitchen);
	this->rooms.push_back(garden);
	this->rooms.push_back(basement);
	// MOVIMIENTOS

	// ITEMS
	Item* keysHouse = new Item("LLAVES", "Menos mal que el vecino tenia una copia...", neighbourHouse);
	Item* baseballBat = new Item("BATE", "Ya tiene sus años, pero para protegerme esta bien", playerBedroom);
	this->items.push_back(keysHouse);
	this->items.push_back(baseballBat);

	// PERSONAJES
	// NPCs
	Npc* neighbour = new Npc("Lola", "neighbour", neighbourHouse);
	Npc* dad = new Npc("John", "dad", parentsBedroom);
	Npc* thief = new Npc("Thief", "Final boss", basement);
	// PLAYER
	string namePlayer;
	std::cout << "Give me your name, hero!\n" << ">";
	std::getline(std::cin, namePlayer);
	// TODO: Setear el nombre del jugador aqui;
	this->player = new Player(namePlayer, "Let's start the adventure!", neighbourHouse);
	std::cout << "Welcome, " << this->player->getName() << "! " << this->player->getDescription() << "\n";
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

bool World::takeItem(string nameItem)
{
	bool result = false;
	string actualRoom = this->player->getLocation()->getName();
	for (int i = 0; i < items.size(); i++) {
		// Primero comprobamos el nombre del objeto que queremos
		if (nameItem == items[i]->getName()) {
			// Despues comprobamos si el jugador y el objeto estan en la misma sala
			if (actualRoom == items[i]->getLocation()->getName()) {
				if (!items[i]->getIsAlreadyTaken()) {
					items[i]->setIsAlreadyTaken(true);
					this->player->inventory.push_back(items[i]);
					result = true;
				}
			}
		}
		//std::cout << items[i]->getName();
		
	}
	return result;
}

