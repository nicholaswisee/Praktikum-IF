#include "Dog.hpp"
#include <iostream>

Dog::Dog(string name, int age, bool trained)
    : Pet(name, age), trained(trained) {
    if (trained) {
        cout << "[DOG] " << name << " entered as trained dog" << endl;
    } else {
        cout << "[DOG] " << name << " entered as untrained dog" << endl;
    }
}

Dog::~Dog() { cout << "[DOG] " << name << " barks goodbye" << endl; }

void Dog::makeSound() const { cout << "[SOUND] " << name << ": Woof!" << endl; }

void Dog::play() {
    if (trained) {
        happiness += 25;
        cout << "[PLAY] " << name
             << " fetches the ball! Happiness: " << happiness << endl;
    } else {
        happiness += 10;
        cout << "[PLAY] " << name << " runs around! Happiness: " << happiness
             << endl;
    }
}
