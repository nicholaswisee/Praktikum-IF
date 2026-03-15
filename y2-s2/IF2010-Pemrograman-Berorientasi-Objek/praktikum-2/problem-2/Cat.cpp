#include "Cat.hpp"
#include <iostream>

Cat::Cat(string name, int age, bool indoor) : Pet(name, age), indoor(indoor) {
    if (indoor) {
        cout << "[CAT] " << name << " entered as indoor cat" << endl;
    } else {
        cout << "[CAT] " << name << " entered as outdoor cat" << endl;
    }
}

Cat::~Cat() { cout << "[CAT] " << name << " meows goodbye" << endl; }

void Cat::makeSound() const { cout << "[SOUND] " << name << ": Meow!" << endl; }

void Cat::play() {
    if (indoor) {
        happiness += 15;
        cout << "[PLAY] " << name
             << " plays with yarn! Happiness: " << happiness << endl;
    } else {
        happiness += 20;
        cout << "[PLAY] " << name << " chases mice! Happiness: " << happiness
             << endl;
    }
}

void Cat::feed() {
    happiness += 8;
    cout << "[FEED] " << name << " eats fish! Happiness: " << happiness << endl;
}
