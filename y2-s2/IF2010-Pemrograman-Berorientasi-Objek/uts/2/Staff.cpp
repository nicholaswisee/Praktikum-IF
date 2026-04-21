#include "Staff.hpp"
#include "Formatter.hpp"

Staff::Staff(string name, int age, string contractEnd, string coachingLicense, string department) : ClubMember(name, age, contractEnd), coachingLicense(coachingLicense), department(department)

// TODO: Constructor
{
}

double Staff::calculateWage() const
{
    return 50000;
    // TODO: return fixed wage, yaitu 50000.
}

Staff::~Staff()
{
    Formatter::log("~Staff", name, "session record freed.");
    // TODO: log destruction menggunakan Formatter::log
}
