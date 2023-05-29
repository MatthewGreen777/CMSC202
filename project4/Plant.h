#ifndef _PLANT_H_
#define _PLANT_H_

#include "Entity.h"

class Plant: public Entity {
 public:
  // Name: Plant() - Default Constructor
  // Description: Creates a new plant
  // Preconditions: None
  // Postconditions: Can create a plant
  Plant();
  // Name: Plant(string name, int hp) - Overloaded constructor
  // Description: Creates a new plant
  // Preconditions: None
  // Postconditions: Can be used to populate plant or child classes
  Plant(string, int);
  // Name: ~Plant - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Plant();
  // Name: Attack()
  // Description: Describes attack statements for plant
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Tells player that plant does not have special attack
  // may be used for child class special attacks
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack();
};
#endif
