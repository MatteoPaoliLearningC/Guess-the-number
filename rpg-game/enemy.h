#ifndef ENEMY_H
#define ENEMY_H

#include "character.h" 

class Enemy : public Character {
 public:
  Enemy() : Character("Foe", 30, 8, 8) {}
};

#endif  // ENEMY_H