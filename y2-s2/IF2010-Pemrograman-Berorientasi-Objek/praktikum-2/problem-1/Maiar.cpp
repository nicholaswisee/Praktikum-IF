#include "Maiar.hpp"
#include <iostream>

Maiar::Maiar(string name, int hp, int power)
    : Creature{name, hp}, power{power} {}

void Maiar::describe() const {
    cout << "Maiar [" << name << "] | HP: " << hp << " | Power: " << power
         << endl;
}

int Maiar::getPower() const { return power; }
