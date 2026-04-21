#pragma once
#include "ClubMember.hpp"
#include <string>

class Staff : public virtual ClubMember // TODO: tentukan mode inheritance yang benar
{
protected:
    string coachingLicense;
    string department;
    // TODO: deklarasikan atribut kelas (coachingLicense, department)

public:
    Staff(string name, int age, string contractEnd, string coachingLicense, string department);
    double virtual calculateWage() const;
    string virtual getSpecialty() const = 0;
    virtual ~Staff();
    // TODO: deklarasikan constructor, methods calculateWage() dan pure virtual getSpeciality(), serta destructor
};
