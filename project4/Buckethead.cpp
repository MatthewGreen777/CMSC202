/********************************************************
** File: Buckethead.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header, parent, and grandparent
** headers and define them
**********************************************************/

#include "Buckethead.h"

// constructor not used
Buckethead::Buckethead() {

}

// overloaded constructor
Buckethead::Buckethead(string name, int hp) {
    SetName(name);
    SetHealth(hp);
}

// define special attack of a buckethead
int Buckethead::SpecialAttack() {
    int specialDamage = 1;
    cout << GetName() << " throws its bucket at you!" << endl;
    cout << GetName() << " deals " << specialDamage << " point of damage" << endl;
    return specialDamage;
}
