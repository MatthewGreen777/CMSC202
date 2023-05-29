/********************************************************
** File: Train.cpp
** Project: CMSC 202 Project 3
** Author: Matthew Green
** Date: 28/10/2020
** Email: mgreen11@umbc.edu
**
** Description: Defines the functions set in the .h file
**********************************************************/
#include "Route.h"
#include "Passenger.h"
#include "Train.h"
#include <vector>

// Overloaded constructor
Train::Train(Route* route) {
  // sets the private variables from the header file
  m_head = nullptr;
  m_route = route;
  m_totalCars = 0;
  AddCar(); // calls the AddCar function
}

// Destructor
Train::~Train() {
    Car* current = m_head; // create a car pointer
    // loop until current is null
    while (current != nullptr) {
      m_head = m_head->m_next; // set head equal to next stop
      // loop until all the passengers are deleated
      for (unsigned int i = 0; i < current->m_passengers.size(); i++) {
        delete current->m_passengers.at(i); // deleate passenger at i
      }
      delete current; // deleate current car
      current = m_head; // set current euqla to head
    }
    // reset values
    m_head = nullptr;
    m_route = nullptr;
    m_totalCars = 0;
}

void Train::AddCar() {
    m_totalCars++; // increase total car value
    Car* newCar = new Car(CAR_CAPACITY, m_totalCars); // create new Car
    Car* current = m_head; // set pointer equal to head
    // set head to newCar is head is null
    if (m_head == nullptr) {
      m_head = newCar;
    } else {
      // loops until the next car is null
      while (current->m_next != nullptr) {
        current = current->m_next;
      }
      current->m_next = newCar; // set the next car to newCar
    }
}

void Train::RemoveCar(Car* remove) {
  
}

void Train::TrainStatus() {
  Car* current = m_head; // set pointer to head
  cout << "Number of Cars: " << m_totalCars << endl; // print total number of cars
  // loops until gone through all vehicles
  for (int i = 0; i < m_totalCars; i++) {
    // print number of passenger in car
    cout << "Car " << current->m_carNumber << ": Number of Passengers: " << current->m_passengers.size() << endl;
    current = current->m_next; // set currnet equal to next car
  }
  m_route->PrintRouteDetails(); // calls funtion from Route
}

void Train::LoadPassengers(string passName) {
  Passenger* passenger; // create passenger
  ifstream openFile(passName); // opens file
  string firstName = " "; // create four strings to hold data
  string lastName = " ";
  string age = " ";
  string startLocation = " ";
  string endLocation = " ";
  // loops not more data is read from file
  while (getline(openFile, firstName, ',')) {
    getline(openFile, lastName, ',');
    getline(openFile, age, ',');
    getline(openFile, startLocation, ',');
    getline(openFile, endLocation, '\n');
    // set values of passenger
    passenger = new Passenger(firstName + " " + lastName, stoi(age), startLocation, endLocation);
    BoardPassenger(passenger); // calls the BoardPassenger function
  }
  openFile.close(); // closes the file
}

void Train::BoardPassenger(Passenger* passenger) {
  Car* current = m_head;
  // adds passenger if start location is equal to current location
  if (passenger->GetStartLocation() == m_route->GetCurrentStop()->GetName()) {
    if (IsTrainFull()) {
      AddCar();
      current = current->m_next;
      cout << "Current car Is Full - Adding Car " << current->m_carNumber << endl;
    } 
    while (current->IsFull()) {
      current = current->m_next;
    }
    current->m_passengers.push_back(passenger); // adds pasenger to vector
    // prints out passenger name
    cout << passenger->GetName() << " Boards the Train (Destination: " << passenger->GetFinalDestination() << ")" << endl;
  } else {
    delete passenger; // delete passenger
  }
}

void Train::DisembarkPassengers() {
  Car* current = m_head; // create pointer equal to head
  int exit = 0; // create int to keep track of how many passengers left
  // loop until current is null
  while (current != nullptr) {
    // loop through the car
    for (unsigned int i = 0; i < current->m_passengers.size(); i++) {
      // disembarks passenger if final destination is equal to to current destination
      if (current->m_passengers.at(i)->GetFinalDestination() == m_route->GetCurrentStop()->GetName()) {
        // print name of passenger that left
        cout << current->m_passengers.at(i)->GetName() << " Disembarks the Train (Destination: " << current->m_passengers.at(i)->GetFinalDestination() << ")" << endl;
        delete current->m_passengers.at(i); // dealocate the pointer
        current->m_passengers.erase(current->m_passengers.begin() + i); // erases that passenger from vector
        exit++; // adds one
      }
    }
    current = current->m_next; // set current to next Car
  }
  cout << exit << " Passengers has disembarked" << endl; // print total amount of people who left
}

void Train::TravelToNextStop() {
  // move to next stop if not null
  if (m_route->GetCurrentStop()->GetNextStop() != nullptr) {
    // set current stop to the next stop
    m_route->SetCurrentStop(m_route->GetCurrentStop()->GetNextStop());
    // print what stop arriving at
    cout << "Arriving at " << m_route->GetCurrentStop()->GetName() << endl;
  } else {
    // tell user to turn around since at end
    cout << "You have reached the end of the rail. Please turn around" << endl;
  }
}

void Train::TurnTrainAround() {
  // turn train around if at end of rail
  if (m_route->GetCurrentStop()->GetNextStop() == nullptr) {
    cout << "Turning train around" << endl; // print messsage of turning train around
    m_route->ReverseRoute(); // calls the ReverseRoute function from Route
  } else {
    // print message telling user they must be at the end of the route
    cout << "You must be at the end of the rail to turn around" << endl;
  }
}

bool Train::IsTrainFull() {
  Car* current = m_head; // create pointer equal to head
  int totalRiders = 0; // declare int to track how many rider
  bool full = true; // create boolean
  // loop to add total passengers
  while ((current != nullptr)) {
    totalRiders = totalRiders + current->m_passengers.size();
    current = current->m_next;
  }
  // train is full if total riders is greater than the product of the number of cars and capacity
  if (totalRiders >= (CAR_CAPACITY * m_totalCars)) {
    full = true;
  } else {
    full = false;
  }
  return full;
}