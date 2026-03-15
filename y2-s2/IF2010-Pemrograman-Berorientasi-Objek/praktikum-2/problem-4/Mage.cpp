#include "Mage.hpp"
#include <iostream>

Mage::Mage(string characterId, string name, int hp, int level, int mana)
    : Character(characterId, name, hp, level), mana(mana) {
    cout << "[CREATE] Mage " << name << " with " << mana << " mana ready"
         << endl;
}

void Mage::castSpell() const {

    cout << "[CAST] " << name << " casts a spell using " << getMana() << " mana"
         << endl;
}

int Mage::getMana() const { return mana; }

Mage::~Mage() { cout << "[DELETE] Mage " << name << " destroyed\n"; }
