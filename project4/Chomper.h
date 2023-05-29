#ifndef _CHOMPER_H_
#define _CHOMPER_H_

#include "Plant.h"

//Sweet plant that chomps zombies - think Little Shop of Horrors
class Chomper: public Plant {
 public:
  // Name: Chomper() - Default Constructor
  // Description: Creates a new chomper
  // Preconditions: None
  // Postconditions: Can create a chomper
  Chomper();
  // Name: Chomper(string name, int hp)
  // Description: Creates a new chomper
  // Preconditions: None
  // Postconditions: Can create a chomper
  Chomper(string, int);
  // Name: ~Chomper - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Chomper();
  // Name: SpecialAttack
  // Description: Defines the Chomper's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
