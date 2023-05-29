/********************************************************
** File: Room.cpp
** Project: CMSC 202 Project 4
** Author: Matthew Green
** Date: 12/11/2020
** Email: mgreen11@umbc.edu
**
** Description: Define the functions declared in the header
** file
**********************************************************/
#include "Room.h"

Room::Room(int ID, string name, string desc, int north, int east, int south, int west) {
m_ID = ID;
m_name = name;
m_desc = desc;
m_direction[0] = north;
m_direction[1] = east;
m_direction[2] = south;
m_direction[3] = west;
}

// Accessors
string Room::GetName() {
    return m_name;
}

// Accessors
int Room::GetID() {
    return m_ID;
}

// Accessors
string Room::GetDesc() {
    return m_desc;
}

// checks if input direction is an exit
int Room::CheckDirection(char myDirection) {
    direction compass; // declare compass from enum
    if ((myDirection == 'N') || (myDirection == 'n')) {
        compass = n; // set compass
        return m_direction[compass]; // return int in array location
    } else if ((myDirection == 'E') || (myDirection == 'e')) {
        compass = e;
        return m_direction[compass];
    } else if ((myDirection == 'S') || (myDirection == 's')) {
        compass = s;
        if (m_direction[compass] != -1) {
        return m_direction[compass];
        }
    } else if ((myDirection == 'W') || (myDirection == 'w')) {
        compass = w;
        return m_direction[compass];
    }
    return -1;
}

// prints details about the room
void Room::PrintRoom() {
    cout << "Room: " << GetName() << endl;
    cout << "Description: " << GetDesc() << endl;
    cout << "Possible Exits: ";
    // checks each direction if it is an exit
    if (CheckDirection('N') != -1) {
        cout << "N";
    }
    if (CheckDirection('E') != -1) {
        cout << "E";
    }
    if (CheckDirection('S') != -1) {
        cout << "S";
    }
    if (CheckDirection('W') != -1) {
        cout << "W";
    }
    cout << endl;
}