#include <iostream>
#include <string>
using namespace std;
#include "Tqueue.cpp"

// To test just queue follow these instructions:
//   1.  make ttest
//   2.  make ttest2


int main () {
  const int SIZE = 10;

  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Enqueue Running" << endl;
  //Test Default Constructor
  Tqueue <int, 10> *newTQ1 = new Tqueue <int, SIZE>();
  //Push 4 nodes into Lqueue
  newTQ1->Enqueue(10);
  newTQ1->Enqueue(30);
  newTQ1->Enqueue(20);
  cout << "After 3 Enqueues size: " << newTQ1->Size() << endl;
  newTQ1->DisplayAll();
  cout << "End Test 1 - Constructor and Enqueue" << endl << endl;
    
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor Running" << endl;
  //Test Copy constructor
  Tqueue <int, 10> *newTQ2 = new Tqueue <int, SIZE>(*newTQ1);
  newTQ2->DisplayAll();
  cout << "Size below should match. Location should not" << endl;
  cout << "Source size: " << newTQ1->Size() << " and Copied size: " << newTQ2->Size() << endl;
  cout << "Source location: " << &newTQ1 << " and Copied location: " << &newTQ2 << endl;
  cout << "End Test 2 - Copy" << endl << endl;
  
  //Test 3 - Overloaded Assignment Operator
  cout << "Test 3 - Overloaded Assignment Operator Running" << endl;
  //Create new Tqueue using constructor
  Tqueue <int, 10> *newTQ3 = new Tqueue <int, SIZE>();
  //Update using overloaded assignment operator
  *newTQ3 = *newTQ1;
  newTQ3->DisplayAll(); //Display contents of newTQ3
  cout << "Size below should match. Location should not" << endl;
  cout << "Source size: " << newTQ1->Size() << " and Assigned size: " << newTQ3->Size() << endl;
  cout << "Source location: " << &newTQ1 << " and Assigned location: " << &newTQ3 << endl;
  cout << "End Test 3 - Assignment" << endl << endl;
  
  //Test 4 - Test Dequeue
  cout << "Test 4 - Dequeue" << endl;
  cout << "Size before: " << newTQ1->Size() << " ";
  newTQ1->Dequeue();
  cout << "Size after: " << newTQ1->Size() << endl;
  cout << "End Test 4 - Dequeue" << endl << endl;
  
  //Test 5 - Test Overloaded []
  cout << "Test 5 - Test Overloaded []" << endl;
  cout << "newTQ1 size = " << newTQ1->Size() << endl;
  for(int i = 0; i < newTQ1->Size(); i++){
    cout << newTQ1->At(i) << endl;
  }
  cout << "End Test 5 - Overloaded []" << endl << endl;

  //Test 6 - Test Sort
  cout << "Test 6 - Sort" << endl;
  cout << "newTQ2 size = " << newTQ2->Size() << endl;
  cout << "newTQ2 before sort = " << endl;
  newTQ2->DisplayAll();
  newTQ2->Sort();
  cout << "newTQ2 after sort = " << endl;
  newTQ2->DisplayAll();
  cout << "End Test 6 - Sort" << endl << endl;
  
  
  //Test 6 - Test Destructor
  cout << "Test 6 - Test Destructor" << endl;
  cout << "delete newTQ1" << endl;
  delete newTQ1;
  cout << "delete newTQ2" << endl;
  delete newTQ2;
  cout << "delete newTQ3" << endl;
  delete newTQ3;
  cout << "End Test 6 - Destructors" << endl;
  return 0;
}
