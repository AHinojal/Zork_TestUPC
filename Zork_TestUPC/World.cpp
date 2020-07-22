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
	Room* porch = new Room("PORCHE", "Estas enfrente de la entrada de tu casa. A tu izquierda esta la casa de tu vecino Paco.\nPara entrar necesitas unas llaves. Casualmente saliste sin ellas y tendras que arreglartelas.\nEs posible que el vecino tenga una copia de ellas...");
	Room* neighbourHouse = new Room("ENTRADA DE LA CASA DEL VECINO", "Estas en la entrada de la casa de tu vecino Paco.\nSu mujer se encuentra en el porche, sentada en una silla.\nA tu derecha, se encuentra tu casa.");
	Room* hall = new Room("SALON", "Por fin estas en casa!! No hay ninguna luz encendida y escuchas un sonido, pero no sabes de donde proviene.\nSi quieres volver a la entrada, esta al sur. Puedes dirigirte tambien a tu izquierda, que esta la habitacion de tus padres o a la derecha, la cocina.\nAdemas, delante tuya tienes tu habitacion.");
	Room* parentsBedroom = new Room("HABITACION DE TUS PADRES", "Te encuentras a tu madre ya dormida y a tu padre viendo la tele a un volumen altisimo.\nEl sonido que has escuchado en el salon podria proveenir de aqui...\nDebajo tienes el aseo y al oeste, volverias al salon.");
	Room* playerBedroom = new Room("HABITACION DEL JUGADOR", "La habitacion esta hecha un desastre. Encima de la cama tienes los libros de clase y en el suelo, tienes tirada la mochila con el material de beisbol.\nSi quieres volver al salon, esta al sur. Al este, tienes el aseo.");
	Room* bathroom = new Room("ASEO", "El aseo esta completamente vacio. No hay nada de utilidad.\nLa habitacion de tus padres la tienes al sur y la tuya, al oeste.");
	Room* kitchen = new Room("COCINA", "Tus padres te han dejado la cena preparada en el plato. Inexplicablemente, te falta el cuchillo en la mesa.\nTambien te das cuenta que la puerta del sotano esta entreabierta. Para ir ahi, ve al sur.\nSi quieres volver al salon, dirigete hacia el este. Tambien puedes dirigirte a la terraza, la cual tienes enfrente.");
	Room* garden = new Room("JARDIN", "La puesta estaba un poco abierta...\nEsta todo muy tranquilo. Rara vez hay robos en el vecindario.\nPero nunca se sabe...\nVuelve atras para regresar a la cocina.");
	Room* basement = new Room("SOTANO", "Bajas las escaleras y por sorpresa, te encuentras a un ladron robando.\nParece que no te ha visto. Te toca enfrentarte a el.");
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
	Item* keysHouse = new Item("LLAVES", "Menos mal que los vecinos tenian una copia...", neighbourHouse);
	Item* dinner = new Item("COMIDA", "Se nota que la cena se preparo hace horas, esta fria...", kitchen);
	Item* baseballBat = new Item("BATE", "Ya tiene su tiempo, pero para protegerme en una emergencia, esta bien...", playerBedroom);
	Item* baseballGlove = new Item("GUANTE", "Es el viejo guante de papa. Le tiene mucho aprecio, y aun asi me lo regalo...", playerBedroom);
	Item* baseballCap = new Item("GORRA", "Me compre esta gorra de los New York Yankees cuando fui a ver uno de sus partidos...", playerBedroom);
	this->items.push_back(keysHouse);
	this->items.push_back(dinner);
	list<Entity*> itemsBaseballBag = {};
	itemsBaseballBag.push_back(baseballBat);
	itemsBaseballBag.push_back(baseballGlove);
	itemsBaseballBag.push_back(baseballCap);
	Item* baseballBag = new Item("MOCHILA", "Contiene los siguientes items dentro: BATE, GUANTE, GORRA", itemsBaseballBag, playerBedroom);
	this->items.push_back(baseballBag);

	// MOVIMIENTOS
	Exit* move1 = new Exit("NORTE", "", NORTE, porch, hall, true, keysHouse);
	Exit* move3 = new Exit("SUR", "", SUR, hall, porch, false, NULL);
	Exit* move2 = new Exit("OESTE", "", OESTE, porch, neighbourHouse, false, NULL);
	Exit* move4 = new Exit("ESTE", "", ESTE, neighbourHouse, porch, false, NULL);
	Exit* move5 = new Exit("OESTE", "", OESTE, hall, parentsBedroom, false, NULL);
	Exit* move6 = new Exit("ESTE", "", ESTE, parentsBedroom, hall, false, NULL);
	Exit* move7 = new Exit("NORTE", "", NORTE, hall, playerBedroom, false, NULL);
	Exit* move8 = new Exit("SUR", "", SUR, playerBedroom, hall, false, NULL);
	Exit* move9 = new Exit("ESTE", "", ESTE, hall, kitchen, false, NULL);
	Exit* move10 = new Exit("OESTE", "", OESTE, kitchen, hall, false, NULL);
	Exit* move11 = new Exit("NORTE", "", NORTE, parentsBedroom, bathroom, false, NULL);
	Exit* move12 = new Exit("SUR", "", SUR, bathroom, parentsBedroom, false, NULL);
	Exit* move13 = new Exit("ESTE", "", ESTE, bathroom, playerBedroom, false, NULL);
	Exit* move14 = new Exit("OESTE", "", OESTE, playerBedroom, bathroom, false, NULL);
	Exit* move15 = new Exit("SUR", "", SUR, garden, kitchen, false, NULL);
	Exit* move16 = new Exit("NORTE", "", NORTE, kitchen, garden, false, NULL);
	Exit* move17 = new Exit("SUR", "", SUR, kitchen, basement, false, NULL);
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

	// PERSONAJES
	// NPCs
	Npc* neighbour = new Npc("LOLA", "Que alto estas, bonito! Toma! Coge las llaves de tu casa!", neighbourHouse);
	Npc* dad = new Npc("PAPA", "Que haces a estas horas despierto, hijo?", parentsBedroom);
	Npc* thief = new Npc("THIEF", "Esto no deberia estar pasando...", basement);
	this->npcs.push_back(neighbour);
	this->npcs.push_back(dad);
	this->npcs.push_back(thief);
	// PLAYER
	string namePlayer;
	std::cout << "Give me your name, hero/heroin!\n" << ">";
	std::getline(std::cin, namePlayer);
	std::cout << "\n";
	// Seteo introduccion del nombre del jugador aqui
	this->player = new Player(namePlayer, "Let's start the adventure!", porch);
	std::cout << "Welcome, " << this->player->getName() << "! " << this->player->getDescription() << "\n\n";
	std::cout << "NOTE: If you want help, put command HELP to open this menu." << "\n\n";
	this->player->getLocation()->showInfo();
	std::cout << "\n";
}

World::~World()
{
	
}

void World::showHelpComands()
{
	std::cout << "COMANDOS:" << "\n";
	std::cout << "- HELP" << " : " << "Abrimos el menu de ayuda." << "\n";
	std::cout << "- VER" << " : " << "Sale la descripcion de la sala actual donde se encuentra el jugador." << "\n";
	std::cout << "- COGER" << " : " << "Guardamos item en el inventario, si se puede." << "\n";
	std::cout << "- SOLTAR" << " : " << "Eliminamos item del inventario, si se puede." << "\n";
	std::cout << "- IR [COORDENADA]" << " : " << "Indicamos el movimiento del jugador. Tipo de coordenadas: NORTE, SUR, ESTE, OESTE." << "\n";
	std::cout << "- DIALOGAR" << " : " << "Hacemos interaccion entre NPC y jugador." << "\n";
	std::cout << "- ATACAR" << " : " << "Nos permite realizar un ataque si el jugador tiene un objeto para ello y si podemos hacerlo." << "\n";
	std::cout << "- INVENTARIO" << " : " << "Vemos todos los objetos que tiene almacenados el jugador." << "\n";
	std::cout << "- LIMPIAR" << " : " << "Limpiamos el terminal de comandos. Podemos consultar todo lo anterior, si subimos el scroll." << "\n";
	std::cout << "- QUIT" << " : " << "Salimos del juego." << "\n";
}

void World::showActualRoom()
{
	this->player->getLocation()->showInfo();
}

bool World::tryChangeRoom(string direction)
{
	bool isChangedRoom = false;
	Exit* move = getPossibleDestination(direction);
	if (move != NULL) {
		// Comprobamos si la habitacion necesita llave
		if (!move->getIsLocked()) {
			this->player->setLocation(move->getDestination());
			isChangedRoom = true;
		} else {
			// Comprobamos si tenemos la llave en el inventario
			vector<Item*> actualInventory = this->player->getInventory();
			for (int i = 0; i < actualInventory.size(); i++) {
				if (actualInventory[i]->getName() == move->getkeyDoor()->getName()) {
					this->player->setLocation(move->getDestination());
					isChangedRoom = true;
				}
			}
			if (!isChangedRoom) {
				std::cout << "CERRADO! No tienes el objeto necesario para ir a la siguiente habitacion." << "\n";
			}
		}
	}
	return isChangedRoom;
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
					// Comentario cogiendo el objeto
					items[i]->showInfo();
					result = true;
				}
			}
		}
	}
	return result;
}

void World::showDialogNpc()
{
	string actualLocationPlayer = this->player->getLocation()->getName();
	string dialogText = "No hay nadie con quien dialogar.";
	for (int i = 0; i < npcs.size(); i++) {
		if (actualLocationPlayer == npcs[i]->getLocation()->getName()) {
			dialogText = npcs[i]->showDialog();
		}
	}
	std::cout << dialogText << "\n";
}

Exit* World::getPossibleDestination(string direction)
{
	Exit* possibleDestination = NULL;
	string actualRoom = this->player->getLocation()->getName();
	// Miramos si hay algun posible movimiento desde la actual habitacion y en la direccion selecciona
	for (int i = 0; i < this->exits.size(); i++) {
		if (exits[i]->getOrigin()->getName() == actualRoom && exits[i]->getName() == direction) {
			possibleDestination = exits[i];
		}
	}
	return possibleDestination;
}