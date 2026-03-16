#ifndef BALROG_H
#define BALROG_H

#include "Maiar.hpp"
using namespace std;

class Balrog : public Maiar {
  private:
    string whipName;

  public:
    Balrog(string name, int hp, int power, string whipName);
    void describe() const override;
    void rage();
};

#endif // !BALROG_H
