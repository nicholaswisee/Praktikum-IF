#include "ClubMember.hpp"
#include "Formatter.hpp"
#include <iostream>

ClubMember::ClubMember(string name, int age, string contractEnd)
    // TODO: constructor
{
    this->name = name;
    this->age = age;
    this->contractEnd = contractEnd;
}

ClubMember::~ClubMember() {
    // TODO: log destruction menggunakan Formatter::log
    Formatter::log("~ClubMember", name, "contract record cleared.");
}


