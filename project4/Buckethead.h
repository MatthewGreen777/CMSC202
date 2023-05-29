#ifndef _BUCKETHEAD_H_
#define _BUCKETHEAD_H_

#include "Zombie.h"

//Silly zombie that wears a bucket on its head
class Buckethead: public Zombie {
 public:
  // Name: Buckethead() - Default Constructor
  // Description: Creates a new buckethead type of zombie
  // Preconditions: None
  // Postconditions: Can create a buckethead
  Buckethead();
  // Name: Buckethead(string name, int hp)
  // Description: Creates a new buckethead
  // Preconditions: None
  // Postconditions: Can create a buckethead
  Buckethead(string, int);
  // Name: SpecialAttack
  // Description: Defines the Buckethead's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
