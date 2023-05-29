/********************************************************
** File: Engineer.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header, parent, and grandparent
** headers and define them
**********************************************************/

#include "Engineer.h"

// constructor not used
Engineer::Engineer() {

}

// overloaded constructor
Engineer::Engineer(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// define special attack of engineer
int Engineer::SpecialAttack() {
    int specailDamage = 2;
    cout << GetName() << " blasts you with thier steam blaster!" << endl;
    cout << GetName() << " deals " << specailDamage << " point of damage" << endl;
    return specailDamage;
}