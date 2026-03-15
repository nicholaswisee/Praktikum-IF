#include "Character.hpp"

Character::Character(string characterId, string name, int hp, int level)
    : characterId(characterId), name(name), hp(hp), level(level) {
    cout << "[CREATE] Character " << characterId << " (" << name
         << ", HP:" << hp << ", Lv:" << level << ") registered\n";
}

Character::~Character() {
    cout << "[DELETE] Character " << characterId << " (" << name
         << ") destroyed\n";
}

string Character::getCharacterId() const { return characterId; }

string Character::getStatus() const {
    return getCharacterId() + " | " + name + " | HP:" + to_string(hp) +
           " | Lv:" + to_string(level);
}

void Character::levelUp() {
    level++;
    hp += 10;
    cout << "[LEVELUP] " << name << " leveled up to Lv:" << level << " with "
         << hp << " HP\n";
}
