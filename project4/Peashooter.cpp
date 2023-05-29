/********************************************************
** File: Peashooter.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header, parent, and grandparent
** headers and define them
**********************************************************/

#include "Peashooter.h"

// constructor not used
Peashooter::Peashooter() {

}

// overloaded constructor
Peashooter::Peashooter(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// destructor not used
Peashooter::~Peashooter() {
    
}

// define special attack for peashooter
int Peashooter::SpecialAttack() {
    int specialDamage = 0;
    specialDamage = rand() % 10 + 3;
    cout << GetName() << " spins up doing GATLING DAMAGE" << endl;
    cout << GetName() << "deals " << specialDamage << " points of damage" << endl;
    return specialDamage;
}