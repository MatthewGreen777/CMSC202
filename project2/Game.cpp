/********************************************************************
 * File: Game.cpp
 * Project: CMSC Project 2, Fall 2020
 * Author: Matthew Green
 * Date: 08/10/2020
 * Section: Lecture Section 30, Discussion section 33
 * E-mail: mgreen11@gl.umbc.edu
 * 
 * Description: Defines and implements the methods and constructer
 * from the Game.h header file
 *********************************************************************/

#include "Game.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

// constructor
Game::Game() {
    // calls and exceutes these methods
    GameTitle();
    LoadShips();
    LoadPirates();
}
// method that loads all the ships from the file
void Game::LoadShips() {
    string type = " "; // declares five string to read in values from the file to be used as the ship characteristics
    string cannon = " ";
    string toughness = " ";
    string speed = " ";
    string desc = " ";
    int counter = 0; // declares an int to keep track of how populated the array is
    // opens up a file up
    ifstream openFile(PROJ2_SHIPS); 
    // while loop to keep running until the file is closed
    while (openFile.is_open()) {
        // for loop to add values to the ship array
        for (counter = 0; counter < MAX_SHIPS; counter++) {
            // uses getline to asign the string values up until a comma
            // or a new line for the description value
            getline(openFile, type, ',');
            getline(openFile, cannon, ',');
            getline(openFile, toughness, ',');
            getline(openFile, speed, ',');
            getline(openFile, desc, '\n');
            // enter these value into the array and uses stoi to convert a string to integers when needed
            m_ships[counter] = {type, stoi(cannon), stoi(toughness), stoi(speed), desc};
        }
        // closes the file
        openFile.close();
    }
    cout << counter << " ships loaded" << endl;
}
// method that loads all the pirates from the file
void Game::LoadPirates() {
    string name = " "; // declares four string to read in values from the file to be used as the pirate characteristics
    string rating = " ";
    string origin = " ";
    string desc = " ";
    int counter = 0; // declares a counter to keep track of how populated the array is
    // opens up a file
    ifstream openFile(PROJ2_PIRATES);
    // while loop to keep running while file is open
    while (openFile.is_open()) {
        // for loop add values to the pirate array
        for (counter = 0; counter < MAX_PIRATES; counter++) {
            // uses getline to asign the string values up until a comma
            // or a new line for the description value
            getline(openFile, name, ',');
            getline(openFile, rating, ',');
            getline(openFile, origin, ',');
            getline(openFile, desc, '\n');
            // enter these values into the array and uses stoi to convert a string to an integer when needed
            m_allPirates[counter] = {name, stoi(rating), origin, desc};
        }
        // closes the file
        openFile.close();
    }
    cout << counter << " pirates loaded" << endl;
}
// method that assigns the user a pirate, a ship, and manages the menu
void Game::StartGame() {
    int playerPirate = 0; // declares an int to be used to know which pirate from the array the player is
    int playerShip = 0; // declares an int to be used to know which ship the player has
    // sets the value of the ship and pirate
    playerPirate = rand() % MAX_PIRATES;
    playerShip = rand() % MAX_SHIPS;
    // sets the pirate to the value that was choses
    m_myPirate = m_allPirates[playerPirate];
    cout << "Congratulations! " << m_myPirate.GetName() << " is now available to plunder!" << endl;
    // sets the ship to the value that was chosen
    m_myPirate.SetCurShip(m_ships[playerShip]);
    cout << m_myPirate.GetName() << " is aboard a " << m_ships[playerShip].m_type << endl;
    // executes the method called
    do {
    MainMenu();
    } while(MainMenu() != 4);
}
// method that creates what the menu looks like
int Game::MainMenu() {
    int input = 0; // declares an int to be used for user input
        cout << "What would you like to do?" << endl;
        cout << "1. Search for Treasure" << endl;
        cout << "2. Repair Ship" << endl;
        cout << "3. See Score" << endl;
        cout << "4. Retire" << endl;
        // asks for user input
        cin >> input;
        cout << "***********************" << endl;
        // checks if user enter the wrong input type
        if (cin.fail()) {
            cout << "Please enter an integer from 1-4" << endl;
            // clears the error flags
            cin.clear();
            // clears the buffer so multiple inputs can't be registered
            cin.ignore(256, '\n');
        } else if (input == 1) {
            // executes the SearchTreasure method if input equals 1
            SearchTreasure();
        } else if (input == 2) {
            // executes the RepairShip method if input equals 2
            m_myPirate.RepairShip();
        } else if (input == 3) {
            // executes the DisplayScore method if input equals 3
            m_myPirate.DisplayScore();
        } else if (input == 4) {
            // ends the game if the input equals 4
            m_myPirate.DisplayScore();
            cout << m_myPirate.GetName() << " sails off into retirement" << endl;
            cout << "Thanks for playing pirates" << endl;
        } else {
            //  executes else if input is less than 1 and greater than 4
            cout << "Please enter an integer from 1-4" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "***********************" << endl;
    return input;
}
// method that details how the user searches for treasure
void Game::SearchTreasure() {
    int input = 0; // declares an int to be used for user input
    // declares an enemy pirate and ship 
    Pirate enemyPirate = m_allPirates[rand() % MAX_PIRATES];
    Ship enemyShip = m_ships[rand() % MAX_SHIPS];
    cout << "You scan the horizan for perspective targets..." << endl;
    cout << "Off in the distance, you see " << enemyPirate.GetName() << " on a " << enemyShip.m_type << endl;
    cout << "What would you like to do" << endl;
    cout << "1. Attack " << enemyPirate.GetName() << endl;
    cout << "2. Attempt to flee from " << enemyPirate.GetName() << endl;
    // while loop runs until input is not 0
    while (input == 0) {
        // asks for user input
        cin >> input;
        if (cin.fail()) {
            cout << "Please enter either 1 or 2" << endl;
            // resets value to 0
            input = 0;
            cin.clear();
            cin.ignore(256, '\n');
        } else if (input == 1) {
            // executes the battle method if input equals 1
            m_myPirate.Battle(enemyPirate, enemyShip);
        } else if (input == 2) {
            // executes the flee method if input equals 2
            m_myPirate.Flee(enemyPirate, enemyShip);
        } else {
            // executes if input less than 1 or greater than 2
            cout << "Please enter either 1 or 2" << endl;
            // resets value to 0
            input = 0;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}
// method that is not used in the program
void Game::RequestShip(int &choice) {
    cout << "This method does nothing" << endl;
}