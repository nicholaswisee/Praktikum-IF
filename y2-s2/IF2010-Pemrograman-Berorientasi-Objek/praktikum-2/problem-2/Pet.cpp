#include "Pet.hpp"

Pet::Pet(string name, int age) : name(name), age(age), happiness(50) {
    cout << "[PET] " << name << " (age " << age << ") entered the store"
         << endl;
}

Pet::~Pet() { cout << "[PET] " << name << " left the store" << endl; }

void Pet::play() {
    happiness += 10;
    cout << "[PLAY] " << name << " is playing! Happiness: " << happiness
         << endl;
}

void Pet::feed() {
    happiness += 5;
    cout << "[FEED] " << name << " is eating! Happiness: " << happiness << endl;
}

void Pet::showStatus() const {
    cout << "[STATUS] " << name << " | Age: " << age
         << " | Happiness: " << happiness << endl;
}

string Pet::getName() const { return name; }

int Pet::getHappiness() const { return happiness; }
