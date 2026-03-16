#ifndef MAIAR_H
#define MAIAR_H
#pragma once
#include "Creature.hpp"

using namespace std;

class Maiar : protected Creature {
  protected:
    int power;
    Maiar(string name, int hp, int power);

  public:
    void describe() const override;
    int getPower() const;
};

#endif
