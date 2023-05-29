#ifndef _GAME_H_
#define _GAME_H_

//Includes of required classes
#include "Room.h"
#include "Entity.h"
#include "Zombie.h"
#include "Plant.h"
#include "Buckethead.h"
#include "Engineer.h"
#include "Imp.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Chomper.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//************************Constants*********************
const int CHOMPER_HEALTH = 12; //starting health for chomper
const int PEASHOOTER_HEALTH = 10;  //starting health for peashooter
const int SUNFLOWER_HEALTH = 15; //starting health for sunflower
const int PLANT_HEALTH = 10; //starting health for plant
const int ENGINEER_HEALTH = 5; //starting health for engineer
const int BUCKETHEAD_HEALTH = 7; //starting health for buckethead
const int IMP_HEALTH = 10; //starting health for imp
const int NUM_RESTS = 1; //starting rests for player
const int NUM_SPECIAL = 3; //starting special attacks for player
const int REST_HEAL = 10; //how much health is restored from rest
const int START_ROOM = 0; //starting room number
//******************************************************

class Game {
public:
  // Name: Game() - Default Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: After asking for a file name, loads map, creates char and starts.
  Game();
  // Name: Game(string filename) - Overloaded Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Uses filesname to LoadMap, calls createplant,
  //                 and sets both numRests and m_numSpecial using constants.
  Game(string);
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated in Game
  ~Game();
  // Name: LoadMap(string fileName)
  // Description: Dynamically creates rooms and inserts them into the m_myMap vector
  // Precondition: File contains map information
  // Postcondition: Map is populated with Room objects.
  void LoadMap(string);
  // Name: PlantCreation()
  // Description: Allows user to create a new plant (or child) to play with. May
  //              be either plant, sunflower, chomper, or peashooter.
  // Preconditions: None
  // Postconditions: m_myCharacter is populated
  void PlantCreation();
  // Name: StartGame()
  // Description: After LoadMap and CharacterCreation, current room
  //              is set (0 by default) and Action is called
  // Preconditions: LoadMap and CharacterCreation must have been completed
  // Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
  void StartGame();
  // Name: Action()
  // Description: Menu for game
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
  void Action();
  // Name: RandomZombie()
  // Description: Used to randomly create a dynamically allocated zombie
  //              of Buckethead, Imp, or Engineer.
  // Preconditions: Has an entity pointer to hold zombie child
  // Postconditions: Returns object of type Buckethead, Imp, or Engineer
  Entity* RandomZombie();
  // Name: Rest
  // Description: If no zombies in current room, allows player to rest
  // Preconditions: Must be valid room with no zombies (room must exist) and have rests
  // Postconditions: Reduces available rests by one and increases hp by 10 REST_HEAL
  void Rest();
  // Name: Move
  // Description: Moves a player from one room to another (updates m_curRoom)
  // Preconditions: Must be valid move (room must exist)
  // Postconditions: Displays room information, checks for new zombie (deletes old)
  void Move();
  // Name: Attack
  // Description: Allows player to attack an enemy entity.
  // Preconditions: Must have enemy zombie in room
  // Postconditions: Indicates who wins and updates health(hp) as battle continues.
  //                 May need to deallocate enemy zombie to prevent memory leaks.
  void Attack();
  // Name: Stats()
  // Description: Displays the information about the player (name, hp, rests, specials)
  // Preconditions: None
  // Postconditions: None
  void Stats();
private:
  vector<Room*> m_myMap; // Vector for holding all rooms in game
  Entity* m_myPlant; // Entity pointer for plant (peashooter, chomper, or sunflower)
  int m_curRoom; // Current room that player (plant) is in
  Entity* m_curZombie; // Current zombie loaded for current room
  int m_numRests; // Number of rests for player (plant)
  int m_numSpecial; // Number of special attacks for player (plant) (refreshed after rests)
};

#endif
