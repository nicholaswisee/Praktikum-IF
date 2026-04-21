#include "Club.hpp"
#include "Player.hpp"
#include "Staff.hpp"
#include <iostream>

Club::Club(std::string name) : clubName{name}
// TODO: constructor
{
}

void Club::addMember(ClubMember *member)
{
    // TODO: push member ke roster
    roster.push_back(member);
}

void Club::printSquadReport() const
{
    std::cout << "\n======================================\n";
    std::cout << "  " << clubName << " - Squad Report\n";
    std::cout << "======================================\n";
    // TODO: panggil getProfile() dari setiap member

    for (ClubMember *member : roster)
    {
        std::cout << member->getProfile() << "\n";
    }
}

void Club::runTraining() const
{
    std::cout << "\n--- Match Day Actions ---\n";
    // TODO: panggil work() dari setiap member
    for (ClubMember *member : roster)
    {
        member->work();
    }
}

Club::~Club()
{
    std::cout << "\n--- Releasing Club Roster ---\n";
    // TODO: delete semua ClubMember* di roster
    for (ClubMember *member : roster)
    {
        delete member;
    }
}
