#include "LandVehicle.hpp"

LandVehicle::LandVehicle(string vehicleId, string brand, int maxSpeed,
                         int numWheels)
    : Vehicle(vehicleId, brand, maxSpeed), numWheels(numWheels) {
  cout << "[CREATE] LandVehicle " << brand << " with " << numWheels
       << " wheels ready" << endl;
}

LandVehicle::~LandVehicle() {
  cout << "[DELETE] LandVehicle " << brand << " destroyed" << endl;
}

void LandVehicle::drive(string destination) const {
  cout << "[DRIVE] " << brand << " (" << numWheels << " wheels) driving to "
       << destination << endl;
}
