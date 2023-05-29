/********************************************************
** File: Chomper.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header, parent, and grandparent
** headers and define them
**********************************************************/

#include "Chomper.h"

// constructor not used
Chomper::Chomper() {

}
// overloaded constructor
Chomper::Chomper(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// destructor not used
Chomper::~Chomper() {
    
}

// define special attack of chomper
int Chomper::SpecialAttack() {
    int sepcialDamage = 0;
    sepcialDamage = rand() % 11 + 2; // int from 2-12
    cout << GetName() << " performs a sneak attack! CHOMP" << endl;
    cout << GetName() << " deals " << sepcialDamage << " points of damage" << endl;
    return sepcialDamage;
}