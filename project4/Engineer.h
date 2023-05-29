#ifndef _ENGINEER_H_
#define _ENGINEER_H_

#include "Zombie.h"

//A zombie that was created in ITE or Engineering building :)
class Engineer: public Zombie {
 public:
  // Name: Engineer() - Default Constructor
  // Description: Creates a new engineer
  // Preconditions: None
  // Postconditions: Can create a engineer
  Engineer();
  // Name: Engineer(string name, int hp)
  // Description: Creates a new engineer
  // Preconditions: None
  // Postconditions: Can create a engineer
  Engineer(string, int);
  // Name: SpecialAttack
  // Description: Defines the Engineer's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
