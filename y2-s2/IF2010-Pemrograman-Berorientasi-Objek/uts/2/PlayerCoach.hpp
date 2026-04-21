#pragma once
#include "Player.hpp"
#include "Staff.hpp"

class PlayerCoach : public Player, public Staff // TODO: tentukan mode inheritance yang benar dan pastikan urutannya tepat
{
private:
    int yearsAsPlayer;
    bool isCurrentlyPlaying;
    // TODO: deklarasikan atribut kelas (yearsAsPlayer, isCurrentlyPlaying)

public:
    PlayerCoach(string name, int age, string contractEnd, string position, int stamina, double rating, string license, int yearsAsPlayer, bool isCurrentlyPlaying);
    void work() const;
    double calculateRating() const;
    string getSpecialty() const;
    double calculateWage() const;
    string getProfile() const;
    ~PlayerCoach();
    // TODO: deklarasikan constructor, methods work(), calculateRating(), getSpecialty(), calculateWage(), getProfile(), dan destructor
};
