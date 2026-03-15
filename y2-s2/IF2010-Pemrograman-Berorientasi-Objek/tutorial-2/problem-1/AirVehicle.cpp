#include "AirVehicle.hpp"

AirVehicle::AirVehicle(string vehicleId, string brand, int maxSpeed,
                       int maxAltitude)
    : Vehicle(vehicleId, brand, maxSpeed), maxAltitude(maxAltitude) {
  cout << "[CREATE] AirVehicle " << brand << " at max altitude " << maxAltitude
       << "m ready" << endl;
}

AirVehicle::~AirVehicle() {
  cout << "[DELETE] AirVehicle " << brand << " destroyed" << endl;
}

void AirVehicle::fly(string destination) {
  cout << "[FLY] " << brand << " (max " << maxAltitude << "m) flying to "
       << destination << endl;
}

string AirVehicle::getBrandName() const { return brand; }

string AirVehicle::showSpec() const { return getSpec(); }
