# Zork_TestUPC

*AUTHOR*: **ALVARO HINOJAL BLANCO**

*LINK*: https://github.com/AHinojal/Zork_TestUPC

#### Description of the game:
> It is a game based on the Zork in 2D (played in terminal), where we control a character through a world (his house), where we can move through the different rooms of the house, talk to NPCs, pick up and drop objects, with the aim of reaching the end of the game and win the game!

> This game is made as an entrance test for the master's degree "ADVANCED PROGRAMMING FOR AAA VIDEO GAMES" @ Universidad Politécnica de Cataluña.

#### Comandos:
- ***HELP***: We opened the help menu.
- ***ROOM***: The description of the current room where the player is located is displayed.
- ***TAKE***: We keep items in inventory, if possible.
- ***DROP***: We remove items from the inventory, if possible.
- ***MOVE [COORDENATE]***: We indicate the player's movement. Type of coordinates: NORTH, SOUTH, EAST, WEST.
- ***TALK***: We do interaction between NPC and player.
- ***ATTACK***: It allows us to make an attack if the player has an object for it and if we can do it.
- ***INVENTORY***: We see all the objects that the player has stored.
- ***CLEAR***: We cleared the command terminal. We can consult all of the above, if we upload the scroll.
- ***QUIT***: Salimos del juego.

#### How to win/lose the game:
###### Win:
You need to take the bag that is in the player's room and when you get to the basement, put the command ATTACK
###### Lose:
1. If you have taken the bag that is in the player's room, if you get to the basement and dialogue with the thief with the command TALK.
2. If you have not taken the bag that is in the player's room, you get to the basement and use either of the two commands (TALK and ATTACK).

#### Map:
![alt Map](https://github.com/AHinojal/Zork_TestUPC/blob/master/Images/map.png?raw=true)

#### Como he cumplido las peticiones del enunciado:
- The code is created on ​Visual Studio 2017 Community​ with minimal level 3 warnings. 
![alt Compilation](https://github.com/AHinojal/Zork_TestUPC/blob/master/Images/compilation.png?raw=true)
![alt List Errors](https://github.com/AHinojal/Zork_TestUPC/blob/master/Images/listErrors.png?raw=true)
- The game does not crash on the main player path. 
  > CHECK! With the gameplays!
- The game content is at least:
  1. Three connected rooms (aim for 5+)
    > As we can see on the map, we have 9 rooms in the game, with one of them connected to 4 rooms (HALL).
  2. Items in the rooms that can be picked up
    > In the game you can take the keys of the house in the neighbour's house, the bag in the player's room and the dinner in the kitchen
  3. Being able to drop items
    > You can release them at any time.
      _NOTE: Objects within an item may NOT be thrown away. You have to throw away the container object!_
    - [![Gameplays ZORK w/ Drop](https://img.youtube.com/vi/Mf22HYL2YVo/0.jpg)](https://www.youtube.com/watch?v=Mf22HYL2YVo?t=69)
  4. Items can be placed inside other items 
    > The bag contains the following items: bat, cap and glove.
    ````
    Item* baseballBat = new Item("BAT", "Is old enough, but to protect me in an emergency, it's okay...", playerBedroom);
    Item* baseballGlove = new Item("GLOVE", "It's Dad's old glove. He's very fond of it, and yet he gave it to me...", playerBedroom);
    Item* baseballCap = new Item("CAP", "I bought this New York Yankees' cap when I went to see one of their games...", playerBedroom);
    list<Entity*> itemsBaseballBag = {};
    itemsBaseballBag.push_back(baseballBat);
    itemsBaseballBag.push_back(baseballGlove);
    itemsBaseballBag.push_back(baseballCap);
    Item* baseballBag = new Item("BAG", "Contains the following items in: BAT, GLOVE, CAP", itemsBaseballBag, playerBedroom);
    ````
  5. Extra feature:
    - NPC Dialog 
      > Including dialogue on the neighbor, the father and the thief when you put in TALK command.
    - Exits that can be closed and only open with keys 
      > The door to the house starts locked and you need the key that the neighbors have.

#### How to execute the game:
To get started, you need to download the zip file with the game release.
After that:
###### En Windows:
- Without need for external programs:
  - Running the file Zork_TestUPC.exe that is inside the Executable folder
- If you have Visual Studio 2017 Community, you can also do it through:
  1. Load the project with the file Zork_TestUPC.sln. You can do it by going to File > Open > Project/Solution > Select Zork_TestUPC.sln.
  2. Compile the project by going to Compile > Complete Solution
  3. Run the game by going to Debug > Start without debugging.

#### Gameplay:
###### Click in the image to see gameplay:
[![Gameplays ZORK](https://img.youtube.com/vi/Mf22HYL2YVo/0.jpg)](https://www.youtube.com/watch?v=Mf22HYL2YVo)

### Enjoy playing the game!


