#pragma once
#include "Character.hpp"

class Warrior : virtual public Character {
  protected:
    int strength;

  public:
    Warrior(string characterId, string name, int hp, int level, int strength);
    int getStrength() const;
    void attack() const;
    ~Warrior();
};
