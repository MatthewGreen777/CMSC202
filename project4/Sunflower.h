#ifndef _SUNFLOWER_H_
#define _SUNFLOWER_H_

#include "Plant.h"

class Sunflower: public Plant {
 public:
  // Name: Sunflower() - Default Constructor
  // Description: Creates a new sunflower
  // Preconditions: None
  // Postconditions: Can create a sunflower
  Sunflower();
  // Name: Sunflower(string name, int hp)
  // Description: Creates a new sunflower
  // Preconditions: None
  // Postconditions: Can create a sunflower
  Sunflower(string, int);
  // Name: ~Sunflower - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Sunflower();
  // Name: SpecialAttack
  // Description: Defines the Sunflower's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
