#pragma once
#include "Mage.hpp"
#include "Warrior.hpp"

class Paladin : public Warrior, public Mage {
  private:
    string holyPower;

  public:
    Paladin(string characterId, string name, int hp, int level, int strength,
            int mana, string holyPower);
    ~Paladin();

    void holyStrike() const;
    string showStatus() const;
};
