#include "Player.hpp"
#include "Formatter.hpp"

Player::Player(string name, int age, string contractEnd, string position, int stamina, double rating) : ClubMember(name, age, contractEnd), position(position), stamina(stamina), rating(rating)
// TODO: constructor
{
}

double Player::calculateWage() const
{
    return rating * 10000.0;
    // TODO: return wage player dengan rumus rating * 10000.0
}

Player::~Player()
{
    Formatter::log("~Player", name, "training log freed.");
    // TODO: log destruction menggunakan Formatter::log
}
