#include "WaterVehicle.hpp"

WaterVehicle::WaterVehicle(string vehicleId, string brand, int maxSpeed,
                           int displacement)
    : Vehicle(vehicleId, brand, maxSpeed), displacement(displacement) {
  cout << "[CREATE] WaterVehicle " << brand << " with " << displacement
       << " tons displacement ready" << endl;
}

WaterVehicle::~WaterVehicle() {
  cout << "[DELETE] WaterVehicle " << brand << " destroyed" << endl;
}

int WaterVehicle::getDisplacement() const { return displacement; }

void WaterVehicle::sail(string destination) const {
  cout << "[SAIL] " << brand << " (" << displacement << " tons) sailing to "
       << destination << endl;
}

string WaterVehicle::showSpec() const { return getSpec(); }
