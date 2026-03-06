#include "Tigreal.hpp"

Tigreal::Tigreal(int atk, int hp) : Hero(atk, hp) {
    cout << "Tigreal udah nongol, atk: " << this->atk << " hp: " << this->hp << "\n";
}

Tigreal::Tigreal() : Tigreal(150, 800) {}

Tigreal::Tigreal(const Tigreal& other) : Hero(other) {
    cout << "Tigreal kloningan berhasil muncul, atk: " << atk << " hp: " << hp << "\n";
}

Tigreal::~Tigreal() {
    cout << "Tigreal udah tiada :(, atk: " << atk << " hp: " << hp << "\n";
}

void Tigreal::useSkill() {
    cout << "Tigreal lagi pake skill, atk: " << atk << " hp: " << hp << "\n";
}

void Tigreal::moveTo(int x, int y) {
    cout << "Tigreal lagi jalan ke " << x << "," << y << ", atk: " << atk << " hp: " << hp << "\n";
}

void Tigreal::taunt(int duration) {
    cout << "Tigreal lagi taunt musuh selama " << duration << " detik, atk: " << atk << " hp: " << hp << "\n";
}

void Tigreal::sacredHammer() {
    cout << "Tigreal pake Sacred Hammer, atk: " << atk << " hp: " << hp << "\n";
}
