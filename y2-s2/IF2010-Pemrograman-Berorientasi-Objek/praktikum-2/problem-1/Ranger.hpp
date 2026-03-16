#ifndef RANGER_H
#define RANGER_H
#include "Creature.hpp"
#include "Elf.hpp"

using namespace std;

class Ranger : public Elf {
  private:
    int arrows;

  public:
    Ranger(string name, int hp, int grace, int arrows);
    void describe() const override;
    void shoot();
};

#endif
