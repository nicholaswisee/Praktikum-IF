#include "Layla.hpp"

Layla::Layla(int atk, int hp) : Hero(atk, hp) {
    cout << "Layla udah nongol, atk: " << this->atk << " hp: " << this->hp << "\n";
}

Layla::Layla() : Layla(10, 500) {}

Layla::Layla(const Layla& other) : Hero(other) {
    cout << "Layla kloningan berhasil muncul, atk: " << atk << " hp: " << hp << "\n";
}

Layla& Layla::operator=(const Layla& other) {
    if (this != &other) {
        Hero::operator=(other);
        cout << "Layla berhasil dicopy, atk: " << atk << " hp: " << hp << "\n";
    }
    return *this;
}

Layla::~Layla() {
    cout << "Layla udah tiada :(, atk: " << atk << " hp: " << hp << "\n";
}

void Layla::useSkill() {
    cout << "Layla lagi pake skill, atk: " << atk << " hp: " << hp << "\n";
}

void Layla::moveTo(int x, int y) {
    cout << "Layla lagi jalan ke " << x << "," << y << ", atk: " << atk << " hp: " << hp << "\n";
}
