#include "Hero.hpp"

Hero::Hero(int atk, int hp) : atk(atk), hp(hp) {
    cout << "hero baru lahir nih, atk: " << this->atk << " hp: " << this->hp << "\n";
}

Hero::Hero(const Hero& other) : atk(other.atk), hp(other.hp) {
    cout << "hero berhasil di-clone, atk: " << atk << " hp: " << hp << "\n";
}

Hero& Hero::operator=(const Hero& other) {
    if (this != &other) {
        atk = other.atk;
        hp  = other.hp;
    }
    return *this;
}

Hero::~Hero() {
    cout << "hero sudah gugur, atk: " << atk << " hp: " << hp << "\n";
}

void Hero::heal(int amount) {
    cout << "hero lagi nyembuhin diri sebanyak " << amount << ", atk: " << atk << " hp: " << hp << "\n";
}

void Hero::moveTo(int x, int y) {
   
}
