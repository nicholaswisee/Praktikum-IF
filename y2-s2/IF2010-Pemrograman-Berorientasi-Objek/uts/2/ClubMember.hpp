#pragma once
#include <string>

using namespace std;

class ClubMember
{
protected:
    // TODO: deklarasikan atribut kelas (name, age, contractEnd)
    string name;
    int age;
    string contractEnd;

public:
    // TODO: deklarasikan constructor, methods getProfile(), calculateWage(), work(), serta destructor
    ClubMember(string name, int age, string contractEnd);

    string virtual getProfile() const = 0;

    double virtual calculateWage() const = 0;

    void virtual work() const = 0;

    virtual ~ClubMember();
};
