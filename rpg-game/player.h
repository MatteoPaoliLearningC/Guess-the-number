#ifndef PLAYER_H
#define PLAYER_H

#include "character.h" 

class Player : public Character {
 public:
  Player(std::string name) : Character(name, 50, 10, 10) {}
};

#endif  // PLAYER_H