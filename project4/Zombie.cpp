/********************************************************
** File: Zombie.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define functions declared in the header file
** and the parent file
**********************************************************/

#include "Zombie.h"

// constructor not used
Zombie::Zombie() {

}

// overloaded constructor not used
Zombie::Zombie(string name, int hp) {

}

// define zombie attack
int Zombie::Attack() {
    int attackDamage = 1;
    cout << GetName() << " deals " << attackDamage << " point of damage" << endl;
    return attackDamage;
}

// define zombie special attack not used
int Zombie::SpecialAttack() {
    return 0; // return so compiler is not angry
}