#include "PlayerCoach.hpp"
#include "Formatter.hpp"
#include <sstream>
#include <vector>

PlayerCoach::PlayerCoach(string name, int age, string contractEnd, string position, int stamina, double rating, string license, int yearsAsPlayer, bool isCurrentlyPlaying)
    : ClubMember(name, age, contractEnd), Player(name, age, contractEnd, position, stamina, rating), Staff(name, age, contractEnd, license, "Coaching"), yearsAsPlayer(yearsAsPlayer), isCurrentlyPlaying(isCurrentlyPlaying)
// TODO: Constructor
{
}

void PlayerCoach::work() const
{
    if (isCurrentlyPlaying)
    {
        Formatter::log("PlayerCoach", name, "plays AND coaches from the pitch.");
    }
    else
    {
        Formatter::log("PlayerCoach", name, "coaches from the touchline.");
    }
    // TODO: log menggunakan Formatter::log, dengan pesan yang berbeda tergantung isCurrentlyPlaying
    // Jika isCurrentlyPlaying -> Output: "[PlayerCoach] Name plays AND coaches from the pitch."
    // else -> Output: "[PlayerCoach] Name coaches from the touchline."
}

double PlayerCoach::calculateRating() const
{
    return rating * 0.7 + (yearsAsPlayer / 20.0) * 3.0;
    // TODO: return rating dengan rumus: rating * 0.7 + (yearsAsPlayer / 20.0) * 3.0
}

std::string PlayerCoach::getSpecialty() const
{
    std::ostringstream oss;
    oss << yearsAsPlayer;
    return "Playing + Coaching (Player-Coach, " + oss.str() + " yrs exp)";
    // TODO: return "Playing + Coaching (Player-Coach, yearsAsPlayer yrs exp)"
}

double PlayerCoach::calculateWage() const
{
    return Player::calculateWage() + Staff::calculateWage();
    // TODO: Jumlahkan calculateWage dari kelas Player and Staff
}

std::string PlayerCoach::getProfile() const
{
    std::vector<std::pair<std::string, std::string>> fields;
    fields.push_back(std::make_pair("Pos", position));
    fields.push_back(std::make_pair("Lic", coachingLicense));
    fields.push_back(std::make_pair("Specialty", getSpecialty()));
    fields.push_back(std::make_pair("Wage", Formatter::wage(calculateWage())));
    return Formatter::makeRow("PlayerCoach", name, fields);
    // TODO: gunakan Formatter::makeRow dengan label "PlayerCoach" dan fields: Pos, Lic, Specialty, Wage
}

PlayerCoach::~PlayerCoach()
{
    Formatter::log("~PlayerCoach", name, "dual-role contract terminated.");
    // TODO: log destruction menggunakan Formatter::log
}
