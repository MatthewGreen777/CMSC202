/********************************************************
** File: Tqueue.cpp
** Project: CMSC 202 Project 5
** Author: Matthew Green and ???
** Date: 03/12/2020
** Email: mgreen11@umbc.edu
**
** Description: Declares and define the functions that a queue
** can use and its properties
**********************************************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: Enqueue
  //Desc: Adds item to the back of queue (checks for capacity)
  //Precondition: Existing Tqueue
  //Postcondition: Size is incremented if successful and m_back increases
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //      **Automatically moves all data to start at index 0 (using loop**
  //Precondition: Existing Tqueue
  //Postcondition: Size is decremented if successful.
  //               Data in m_front is removed and remaining data is move to the front.
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue (any algorithm you like)
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (low to high)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (difference between m_back and m_front)
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: At
  //Precondition: Existing Tqueue with index starting at 0
  //Postcondition: Returns object from Tqueue using At() 
  T& At(int x);//Returns data from queue at location
  //Name: DisplayAll()
  //Precondition: Existing Tqueue (not used in MediaPlayer)
  //Postcondition: Outputs all items in Tqueue (must be cout compatible -
  //               may require overloaded << in object)
  void DisplayAll();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue (for this project should always remain at 0)
  int m_back; //Back of the queue (will increase as the size increases)
};

//**** Add class definition below ****
// Default constructor
template <class T, int N>
Tqueue<T,N>::Tqueue() {
  m_data = new T[N]; // declare new dynamic array
  m_front = 0; // set front value
  m_back = 0; // set back value
  
}

// Overloaded constructor
template <class T, int N>
Tqueue<T,N>::Tqueue(const Tqueue<T,N>& x) {
  m_data = new T[N]; // declare new dynamic array
  m_back = x.m_back; // set back value
  m_front = x.m_front; // set front value
  // loop through and copy existing values to new queue
  for (int i = 0; i < x.m_back; i++) {
    m_data[i] = x.m_data[i];
  }
}

// Destructor
template <class T, int N>
Tqueue<T,N>::~Tqueue() {
  delete[] m_data; // delete dynamic array
  m_data = nullptr;
}

// function that add stuff to queue
template <class T, int N>
void Tqueue<T,N>::Enqueue(T data) {
  if (IsFull()) { // checks if queue is full
    cout << "Queue is full and can't be added too" << endl;
  } else {
    m_data[m_back] = data; // set the data in the position
    m_back++; // increase back value
  }
}

// functino to remove stuff from queue
template <class T, int N>
void Tqueue<T,N>::Dequeue() {
  if (IsEmpty()) { // checks if queue is empty
    cout << "Queue is empty, nothing can be removed" << endl;
  } else { // checks if queue is empty
    m_data[m_front] = 0; // set front position in array to 0
    // for loop to shift data to in array to the left
    for (int i = 0; i < (m_back-1); i++) {
      m_data[i] = m_data[i+1];
    }
    m_data[m_back] = 0; // set back position in array to 0
    m_back--; // decrease back value
  }
}

// function to sort queue
template <class T, int N>
void Tqueue<T,N>::Sort() {
  T one; // declare two integers
  T two;
  // for loop to go through array
  for (int i = 0; i < m_back; i++) {
    one = m_data[i]; // set value of int
    // for loop to go through array and compare to first int
    for (int j = 0; j < m_back; j++) {
      two = m_data[j]; // set value of int
      if (*one < *two) { // swaps position of the two values
        m_data[i] = two;
        m_data[j] = one;
        i--; // decrease i value
        break; // breaks out of second tier loop
      }
    }
  }
}


// checks if array is empty
template <class T, int N>
int Tqueue<T,N>::IsEmpty() {
  if (m_back == 0) {
    return 1;
  } else {
    return 0;
  }
}

// checks if array is full
template <class T, int N>
int Tqueue<T,N>::IsFull() {
  if (m_back == N) {
    return 1;
  } else {
    return 0;
  }
}

// checks for the size of the array
template <class T, int N>
int Tqueue<T,N>::Size() {
  return m_back;
}

// defines the overloaded assignment operator
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=(Tqueue<T,N> y) {
  delete[] m_data; // delete info held in array
  m_data = nullptr;
  m_data = new T[N]; // declare new array
  m_back = y.m_back; // set back value
  m_front = y.m_front; // set front value
  // loop through and copy data to new array
  for (int i = 0; i < y.m_back; i++) {
    m_data[i] = y.m_data[i];
  }
  return *this;
}
// function to return value
template <class T, int N>
T& Tqueue<T,N>::At(int x) {
  return m_data[x];
}

// display everything in the array
template <class T, int N>
void Tqueue<T,N>::DisplayAll() {
  // loop through array
  for (int i = 0; i < m_back; i++) {
    cout << m_data[i] << endl;
  }
}
#endif