#pragma once
#include "ClubMember.hpp"
#include <string>

class Player : public virtual ClubMember // TODO: tentukan mode inheritance yang benar
{
protected:
    string position;
    int stamina;
    double rating;
    // TODO: deklarasikan atribut kelas (position, stamina, rating)

public:
    Player(string name, int age, string contractEnd, string position, int stamina, double rating);
    double virtual calculateWage() const;
    double virtual calculateRating() const = 0;
    virtual ~Player();
    // TODO: deklarasikan constructor, method calculateWage() dan pure virtual calculateRating() serta destructor
};
