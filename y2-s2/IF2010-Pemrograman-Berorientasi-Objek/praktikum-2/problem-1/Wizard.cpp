#include "Wizard.hpp"
#include <iostream>

Wizard::Wizard(string name, int hp, int power, string staffName)
    : Maiar{name, hp, power}, staffName{staffName} {}

void Wizard::describe() const {
    cout << "Wizard [" << name << "] | HP: " << hp << " | Staff: " << staffName
         << endl;
}

void Wizard::cast() {
    cout << name << " channels " << power << " power through " << staffName
         << "!" << endl;
}
