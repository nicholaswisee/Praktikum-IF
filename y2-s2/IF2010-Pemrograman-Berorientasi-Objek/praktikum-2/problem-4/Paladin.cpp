#include "Paladin.hpp"

Paladin::Paladin(string characterId, string name, int hp, int level,
                 int strength, int mana, string holyPower)
    : Character(characterId, name, hp, level),
      Warrior(characterId, name, hp, level, strength),
      Mage(characterId, name, hp, level, mana), holyPower(holyPower) {
    cout << "[CREATE] Paladin " << name << " (" << holyPower << ") ready\n";
}

Paladin::~Paladin() { cout << "[DELETE] Paladin " << name << " destroyed\n"; }

void Paladin::holyStrike() const {
    cout << "[HOLY] " << name << " unleashes " << holyPower << " with "
         << getStrength() << " str and " << getMana() << " mana\n";
}

string Paladin::showStatus() const {
    return getStatus() + " | Str:" + to_string(getStrength()) +
           " | Mana:" + to_string(getMana()) + " | Holy:" + holyPower;
}
