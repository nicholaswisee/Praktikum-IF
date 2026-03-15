#pragma once
#include "Hero.hpp"

class Tigreal : public Hero {
public:
    Tigreal(int atk, int hp);
    Tigreal();
    Tigreal(const Tigreal& other);
    ~Tigreal();

    void useSkill() override;
    void moveTo(int x, int y) override;
    void taunt(int duration);
    void sacredHammer();
};
