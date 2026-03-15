#pragma once
#include <iostream>
using namespace std;

class Hero {
protected:
    int atk, hp;
public:
    Hero(int atk, int hp);
    Hero(const Hero& other);
    Hero& operator=(const Hero& other);
    virtual ~Hero();

    void heal(int amount);
    virtual void useSkill() = 0;
    virtual void moveTo(int x, int y);
};
