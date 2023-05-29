/********************************************************
** File: Route.cpp
** Project: CMSC 202 Project 3
** Author: Matthew Green
** Date: 28/10/2020
** Email: mgreen11@umbc.edu
**
** Description: Defines the functions set in the .h file
**********************************************************/
#include <string>
#include <fstream>
#include <iostream>
#include "Stop.cpp"
#include "Route.h"
using namespace std;

// Constructor
Route::Route() {
    // sets the private variables from the header file
    m_head = nullptr;
    m_tail = nullptr;
    m_currentStop = nullptr;
    m_totalStops = 0;
}

// Desctructor
Route::~Route() {
    Stop* current = m_head; // set current stop to head
    // loop until current is null
    while (current != nullptr) {
        m_head = m_head->GetNextStop(); // set head to next stop
        delete current; // deleates the current stop
        current = m_head; // set current to head
    }
    // reset all values
    m_head = nullptr;
    m_tail = nullptr;
    m_currentStop = nullptr;
    m_totalStops = 0;
}

void Route::LoadRoute(string fileName) {
    string stationName = " "; // declares two string to hold data from file
    string stationNumber = " ";
    ifstream openFile(fileName); // opens file
    // loops through the file until nothing is read
    while (getline(openFile, stationName, ',')) {
        getline(openFile, stationNumber, '\n');
        // Calls the addstop function
        AddStop(stationName, stoi(stationNumber));
    }
    openFile.close(); // closes the file
    m_currentStop = m_head; // set currentStop to head
    cout << "Route loaded with " << m_totalStops << " stops" << endl; // print total number of stops
}

void Route::AddStop(string name, int number) {
  Stop* newStop = new Stop(name, number); // create a new Stop
  // set head and tail to newStop if head is null
  if (m_head == nullptr) {
    m_head = newStop;
    m_tail = newStop;
  } else {
    m_tail->SetNextStop(newStop); // set the stop at the end of the linked list to newStop
    m_tail = newStop; // set tail to newStop
  }
  m_totalStops++; // increase number for total stops
}

void Route::PrintRouteDetails() {
  // prints current stop
  cout << "Current Stop: " << GetCurrentStop()->GetName() << " (" << GetCurrentStop()->GetNumber() << ")"  << endl;
  // prints the next stop unless it is a null
  if (GetCurrentStop()->GetNextStop() != nullptr) {
    cout << "Next Stop: " << GetCurrentStop()->GetNextStop()->GetName() << " (" << GetCurrentStop()->GetNextStop()->GetNumber() << ")" << endl;
  } else {
    // print turn around if reched the end, next stop is null
    cout << "You have reached the end of the rail. Please turn around" << endl;
  }
}

// Accessor
Stop* Route::GetCurrentStop() {
    return m_currentStop;
}

// Mutator 
void Route::SetCurrentStop(Stop* curStop) {
    m_currentStop = curStop;
}

void Route::ReverseRoute() {
    Route* route; // create route pointer
    Stop* current = m_head; // create three stop pointers
    Stop* next = nullptr;
    Stop* prev = nullptr;
    while (current != nullptr) {
        route = new Route();
        route->AddStop(m_currentStop->GetName(), m_currentStop->GetNumber());
        next = current->GetNextStop(); // set next to current next stop
        current->SetNextStop(prev); // set  the next stop to prev
        prev = current; // set prev to current
        current = next; // set current to next
        delete route; // deleate route
    }
    m_head = prev; // set head to prev
    cout << m_totalStops << " stops reversed" << endl; // print route was reversed
}
