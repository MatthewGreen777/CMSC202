/********************************************************
** File: Passenger.cpp
** Project: CMSC 202 Project 3
** Author: Matthew Green
** Date: 28/10/2020
** Email: mgreen11@umbc.edu
**
** Description: Defines the functions set in the .h file
**********************************************************/
#include "Passenger.h"
#include <string>
#include <iostream>
using namespace::std;

// overloaded constructor
Passenger::Passenger(string name, int age, string startLocation, string finalDestination) {
    // sets the private variables from the header file equal to what the parameters are set to
    m_fullName = name;
    m_age = age;
    m_startLocation = startLocation;
    m_finalDestination = finalDestination;

}

// Accessor 
string Passenger::GetName() {
    return m_fullName;
}

string Passenger::GetStartLocation() {
    return m_startLocation;
}

string Passenger::GetFinalDestination() {
    return m_finalDestination;
}
