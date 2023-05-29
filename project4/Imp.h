#ifndef _IMP_H_
#define _IMP_H_

#include "Zombie.h"

//A little mean looking zombie
class Imp: public Zombie {
 public:
  // Name: Imp() - Default Constructor
  // Description: Creates a new imp
  // Preconditions: None
  // Postconditions: Can create an imp
  Imp();
  // Name:  Imp(string name, int hp)
  // Description: Creates a new  imp
  // Preconditions: None
  // Postconditions: Can create an imp
  Imp(string, int);
  // Name: SpecialAttack
  // Description: Defines the Imp's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
