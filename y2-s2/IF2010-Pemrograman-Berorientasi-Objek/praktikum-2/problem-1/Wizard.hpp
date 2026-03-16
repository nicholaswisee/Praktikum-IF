#ifndef WIZARD_H
#define WIZARD_H

#include "Maiar.hpp"

class Wizard : private Maiar {
  private:
    string staffName;

  public:
    Wizard(string name, int hp, int power, string staffName);
    void describe() const override;
    void cast();
};

#endif
