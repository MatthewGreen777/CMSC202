/********************************************************
** File: Game.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Defines all the function from the .h file
** to create the game. 
**********************************************************/

#include "Game.h"

// Game constructor, won't be used
Game::Game() {
    string fileName = " "; // declare string
    cout << "Please enter the name of file (include file extention)" << endl;
    cin >> fileName; // ask user for file name
    LoadMap(fileName); // load file
    cout << "Welcome to UMBC Adventure!" << endl; // welcome message
    PlantCreation(); // call function to create plant
    StartGame(); // call function to start the game
}

// overloaded Game constructor
Game::Game(string fileName) {
    LoadMap(fileName); // load file from parameter
    cout << "Welcome to UMBC Adventure!" << endl; // welcome message
    PlantCreation(); // call function to create plant
    StartGame(); // call function to start the game
}

// destructor
Game::~Game() {
    delete m_myPlant; // dealocates m_myPlant pointer
    delete m_curZombie; // dealocates m_curZombie
    for (unsigned int i = 0; i < m_myMap.size(); i++) {
        delete m_myMap.at(i); // dealocates all the Room pointer in the vector
    }
}

// function to load the map
void Game::LoadMap(string fileName) {
    // declares 7 strings to hold room data
    string ID = " ";
    string name = " ";
    string desc = " ";
    string north = " ";
    string east = " ";
    string south = " ";
    string west = " ";
    string end = " "; // declares this string to move to next line in file
    ifstream open(fileName); // opens the fille
    // while loop to read file
    while (getline(open, ID, '|')) {
        // set the data in the strings until reaching a certain point
        getline(open, name, '|');
        getline(open, desc, '|');
        getline(open, north, '|');
        getline(open, east, '|');
        getline(open, south, '|');
        getline(open, west, '|');
        getline(open, end, '\n');
        // create room with data obtained
        Room *newRoom = new Room(stoi(ID), name, desc, stoi(north), stoi(east), stoi(south), stoi(west));
        m_myMap.push_back(newRoom); // add element to vector
    }
    open.close(); // closes the file
}

// function to creat plant
void Game::PlantCreation() {
    string name = " "; // declare string for plant name
    int classChoice = 0; // declare int for plant class

    cout << "Plant Name: ";
    cin >> name; // ask user for plant name
    cout << "Select a class" << endl;
    // while loop until one of the classes are chosen
    while ((classChoice < 1) || (classChoice > 4)) {
        cout << "1. Peashooter \n2. Chomper \n3. Sunflower \n4. No Class" << endl;
        cin >> classChoice; // ask user to choose plant class
        // ignore input if cin fails
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            classChoice = 0;
        }
        // switch statement to determine plant class and creates that class if chosen
        switch(classChoice) {
            case 1:
                m_myPlant = new Peashooter(name, PEASHOOTER_HEALTH);
                break;
            case 2:
                m_myPlant = new Chomper(name, CHOMPER_HEALTH);
                break;
            case 3:
                m_myPlant = new Sunflower(name, SUNFLOWER_HEALTH);
                break;
            case 4:
                m_myPlant = new Plant(name, PLANT_HEALTH);
                break;
            default:
                cout << "Select a class" << endl;
                break;
        }
    }
}

// function to start the game
void Game::StartGame() {
    m_curRoom = START_ROOM; // set current room to start room  
    m_numRests = NUM_RESTS; // set number of rests
    m_numSpecial = NUM_SPECIAL; // set number of special
    m_curZombie = nullptr; // declare zombie to be null
    m_myMap.at(m_curRoom)->PrintRoom(); // print the current room
    Action(); // call function to declare action
}

// function to decide what action to take
void Game::Action() {
    int action = 0; // declare int to decide action
    cout << "What would you like to do?" << endl;
    // while loop to play game until user does not want to or losses
    while ((action != 6) && (m_myPlant->GetHealth() >= 1)) {
        cout << "1. Look \n2. Move \n3. Attack Zombie \n4. Rest \n5. Check Stats \n6. Quit" << endl;
        cin >> action; // user picks what action to take
        // ignore input if not int
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            action = 0;
        }
        // switch statement to determine action based on input
        switch (action) {
            case 1:
                m_myMap.at(m_curRoom)->PrintRoom(); // print current room
                break;
            case 2:
                Move(); // call move function
                break;
            case 3:
                Attack(); // call attack function
                break;
            case 4:
                Rest(); // call rest function
                break;
            case 5:
                Stats(); // call stats function
                break;
            case 6:
                cout << "Thank you for playing" << endl; // end the game
                break;
            default:
                cout << "What would you like to do?" << endl; // ask player if input is not one of the actions
                break;
        }
        // ends the game if player health is less than or equal to 0
        if (m_myPlant->GetHealth() <= 0) {
            cout << "GAME OVER" << endl;
            cout << "Thank you for playing" << endl;
        }
    }
}

// function to have zombie appear
Entity* Game::RandomZombie() {
    int random = 0; // declare int to see what zombie appear
    random = rand() % 4 + 1; // have int be a number 1-4
    // switch statemnt to see what zombie appears
    switch (random) {
        case 1: // create buckethead zombie
            cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
            m_curZombie = new Buckethead("Buckethead", BUCKETHEAD_HEALTH);
            return m_curZombie;
        case 2: // create engineer zombie
            cout << "A large zombie stand here wearing khakis with a sign that says ENGINEER." << endl;
            m_curZombie = new Engineer("Engineer", ENGINEER_HEALTH);
            return m_curZombie;
        case 3: // create imp zombie
            cout << "A dirty imp licks his lips and glares at you." << endl;
            m_curZombie = new Imp("Imp", IMP_HEALTH);
            return m_curZombie;
        case 4: // no zombie are created
            cout << "It is peaceful here" << endl;
            return m_curZombie = nullptr;
    }
    return nullptr; // return nullptr so compiler is not angry
}

// function to define how rest works
void Game::Rest() {
    if ((m_numRests > 0) && (m_curZombie == nullptr)) { // can rest if these conditions are met
        m_myPlant->SetHealth(m_myPlant->GetHealth() + REST_HEAL); // add health to player
        m_numRests--; // subtract number of rest
    } else if (m_numRests <= 0) { // can't rest without 1 rest
        cout << "You must have at least 1 rest to rest" << endl;
    } else if (m_curZombie != nullptr) { // can't rest with a zombie in the room
        cout << "You can not rest with a zombie in the room" << endl;
    }
}

// function that define how moving works
void Game::Move() {
    char movement = ' '; // declare char to know what direction to move
    cout << "Which direction? (N E S W)" << endl;
    cin >> movement; // user input direction
    // ignore input if wrong input
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        movement = ' ';
    }
    //check if direction is an exit
    if (m_myMap.at(m_curRoom)->CheckDirection(movement) != -1) {
        if (m_curZombie != nullptr) {
            delete m_curZombie; // deleate zombie if there was a zombie in current room
        }
        m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(movement); // changes room
        m_myMap.at(m_curRoom)->PrintRoom(); // print details about new room
        RandomZombie(); // sees if zombie shows up
    } else { // no exit in that direction
        cout << "There is no exit in that direction" << endl;
    }
}

// function to define how attacking works
void Game::Attack() {
    int choice = 0; // declare int for attack type
    int damageDone = 0; // declare int for how much damage done
    if (m_curZombie != nullptr) { // can attack if there is a zombie
        // while loop while the player and zombie has health
        while ((m_myPlant->GetHealth() >= 1) && (m_curZombie->GetHealth() >= 1)) {
            while ((choice > 2) || (choice < 1)) { // loop unitl player chooses
                cout << "1. Normal Attack \n2. Special Attack" << endl;
                cin >> choice; // player enter attack type
                // ignore input if wrong type
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    choice = 0;
                }
                // switch statement for which attack type to do
                switch (choice) {
                    case 1:
                        damageDone = m_myPlant->Attack(); // normal attack
                        break;
                    case 2:
                        if (m_numSpecial <= 0) {
                            cout << "No more special remains, plant does nomral attack" << endl;
                            damageDone = m_myPlant->Attack(); // attack if no special remains
                        } else if (m_numSpecial > 0) {
                            damageDone = m_myPlant->SpecialAttack(); // special attack
                        }
                        break;
                    default:
                        cout << "Choose a choice" << endl; // choose one of the choices
                        break;
                }
            }
            m_curZombie->SetHealth(m_curZombie->GetHealth() - damageDone); // subtract damage done to zombie
            choice = rand() % 4 + 1; // have int be from 1-4
            if (choice > 1) { // normal attack if 2-4
                damageDone = m_curZombie->Attack();
            } else if (choice == 1) { // special attack if 1
                damageDone = m_curZombie->SpecialAttack();
            }
            choice = 0; // reset choice value
            m_myPlant->SetHealth(m_myPlant->GetHealth() - damageDone); // update player health
            // print how much health the player and zombie has
            if ((m_myPlant->GetHealth() >= 1) && (m_curZombie->GetHealth() >= 1)) {
                cout << m_myPlant->GetName() << " health: " << m_myPlant->GetHealth() << endl;
                cout << m_curZombie->GetName() << " health: " << m_curZombie->GetHealth() << endl;
            } else if (m_curZombie->GetHealth() <= 0) { // print message that zombie is defeated
                cout << "You have defeated the " << m_curZombie->GetName() << endl;
            }
        }
        if (m_curZombie->GetHealth() <= 0) {
            delete m_curZombie; // dealocates zombie
            m_curZombie = nullptr; // set zombie to nullptr
        }
    } else { // no attack comenses if there is no zombie
        cout << "There is no zombie to attack" << endl;
    }
}

// function that output player stats
void Game::Stats() {
    cout << *m_myPlant << endl;
    //cout << "Health Remaining: " << m_myPlant->GetHealth() << endl;
    cout << "Rests Left: " << m_numRests << endl;
    cout << "Specials Left: " << m_numSpecial << endl;
}