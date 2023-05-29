/********************************************************
** File: Entity.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions from the header file
** which is the parent class
**********************************************************/

#include "Entity.h"

// constructor not used
Entity::Entity() {
    
}

// overloaded constructor not used
Entity::Entity(string name, int hp) {
    
}

// destructor not used
Entity::~Entity() {

}

// Accessors
string Entity::GetName() {
    return m_name;
}

// Accessors
int Entity::GetHealth() {
    return m_health;
}

// Mutators
void Entity::SetName(string name) {
    m_name = name;
}

// Mutators
void Entity::SetHealth(int health) {
    m_health = health;
}

ostream& operator<<(ostream &output, Entity &E) {
    output << "Plant Name: " << E.m_name << "\nHealth Remaining: " << E.m_health;
    return output;
}