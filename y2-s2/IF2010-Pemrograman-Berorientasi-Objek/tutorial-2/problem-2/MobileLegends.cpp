#include "Layla.hpp"
#include "Tigreal.hpp"
#include <iostream>

using namespace std;

int main() {
  Layla *layla1 = new Layla(10, 1000);
  layla1->useSkill();

  Layla *layla2 = new Layla(*layla1);
  layla2->heal(5);
  Layla *layla3 = new Layla(50, 200);
  layla3->moveTo(15, 30);
  *layla3 = *layla1;

  Tigreal tigreal1(200, 10);
  tigreal1.moveTo(5, 15);
  tigreal1.taunt(10);
  Tigreal tigreal2 = tigreal1;

  Tigreal tigreal3(400, 20);
  tigreal3.sacredHammer();

  Tigreal tigreal4 = tigreal3;
  tigreal1.useSkill();
  tigreal3.useSkill();

  Tigreal tigreal5(300, 15);
  tigreal5.moveTo(10, 20);

  Tigreal *tigreal6 = new Tigreal(tigreal5);
  tigreal6->taunt(5);

  delete tigreal6;
  delete (layla3);
  delete (layla2);
  delete (layla1);
  return 0;
}
