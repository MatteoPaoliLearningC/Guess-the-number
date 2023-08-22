#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
 public:
  Character(std::string name, int health, int attack, int defense) :
      _name(name), _health(health), _attack(attack), _defense(defense) {}

  std::string name() { return _name; }
  int health() { return _health; }
  int defense() { return _defense; }
  int attack() { return _attack; }

 private: 
  std::string _name;
  int _health;
  int _attack;
  int _defense;
};

#endif  // CHARACTER_H
