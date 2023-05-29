#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include "Entity.h"

//The parent class for all of the cute and smelly zombies
class Zombie: public Entity {
 public:
  // Name: Zombie() - Default Constructor
  // Description: Would be used to create a zombie but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Zombie();
  // Name: Zombie(string name, int hp) - Overloaded Constructor
  // Description: Would be used to create a zombie but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Zombie(string, int);
  // Name: Attack()
  // Description: Describes attack statements for zombie
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Purely virtual SpecialAttack
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
  virtual int SpecialAttack()=0;
};
#endif
