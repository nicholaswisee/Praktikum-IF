#include "Parrot.hpp"
#include <iostream>

Parrot::Parrot(string name, int age, int vocabulary)
    : Pet(name, age), vocabulary(vocabulary) {
    cout << "[PARROT] " << name << " entered knowing " << vocabulary << " words"
         << endl;
}

Parrot::~Parrot() { cout << "[PARROT] " << name << " squawks goodbye" << endl; }

void Parrot::makeSound() const {
    cout << "[SOUND] " << name << ": Squawk! I know " << vocabulary << " words!"
         << endl;
}
void Parrot::play() {
    vocabulary++;
    happiness += 10;
    cout << "[PLAY] " << name
         << " learns a new word! Vocabulary: " << vocabulary
         << ", Happiness: " << happiness << endl;
};
void Parrot::feed() {
    happiness += 3;
    cout << "[FEED] " << name << " eats seeds! Happiness: " << happiness
         << endl;
}
