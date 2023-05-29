/********************************************************
** File: Plant.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define functions declared in the header file
** and the parent file
**********************************************************/

#include "Plant.h"

// constructor not used
Plant::Plant() {

}

// overloaed constructor
Plant::Plant(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// desctructor not used
Plant::~Plant() {
    
}

// define attack of a plant
int Plant::Attack() {
    int attackDamage = 0;
    attackDamage = rand() % 6 + 1;
    cout << GetName() << " deals " << attackDamage << " points of damage" << endl;
    return attackDamage;
}

// define the special attack of a plant
int Plant::SpecialAttack() {
    int specialDamage = 0;
    cout << GetName() << " does not have a special attack" << endl;
    return specialDamage;
}