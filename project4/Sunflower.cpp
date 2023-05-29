/********************************************************
** File: Sunflower.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header, parent, and grandparent
** headers and define them
**********************************************************/

#include "Sunflower.h"

// constructor not used
Sunflower::Sunflower() {

}

// overloaded constructor
Sunflower::Sunflower(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// destructor not used
Sunflower::~Sunflower() {
    
}

// define special attack for sunflower
int Sunflower::SpecialAttack() {
    int specialDamage = 0;
    specialDamage = rand() % 8 + 1;
    cout << GetName() << " uses a high beem turet - **SUNBEAM**" << endl;
    cout << GetName() << " deals " << specialDamage << " point of damage" << endl;
    return specialDamage;
}