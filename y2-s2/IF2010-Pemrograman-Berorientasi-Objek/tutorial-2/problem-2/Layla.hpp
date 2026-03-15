#pragma once
#include "Hero.hpp"

class Layla : public Hero {
public:
    Layla(int atk, int hp);
    Layla();
    Layla(const Layla& other);
    Layla& operator=(const Layla& other);
    ~Layla();

    void useSkill() override;
    void moveTo(int x, int y) override;
};
