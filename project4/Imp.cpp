/********************************************************
** File: Imp.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header, parent, and grandparent
** headers and define them
**********************************************************/

#include "Imp.h"

// constructor not used
Imp::Imp() {

}

// overloaded constructor
Imp::Imp(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// define special attack for imp
int Imp::SpecialAttack() {
    int specialDamage = 4;
    cout << GetName() << " blasts you with their impkata attack!" << endl;
    cout << GetName() << " deals " << specialDamage << " point of damage" << endl;
    return specialDamage;
}