#ifndef ELF_H
#define ELF_H

#pragma once
#include "Creature.hpp"
#include <string>
using namespace std;

class Elf : public Creature {
  protected:
    int grace;

  public:
    Elf(string name, int hp, int grace);

    void describe() const override;
    int getGrace() const;
};

#endif
