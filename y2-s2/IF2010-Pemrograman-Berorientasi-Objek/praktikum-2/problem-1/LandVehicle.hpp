#include "Vehicle.hpp"
#include <iostream>
#include <string>

using namespace std;

class LandVehicle : public Vehicle {
protected:
  int numWheels;

public:
  LandVehicle(string vehicleId, string brand, int maxSpeed, int numWheels);
  ~LandVehicle();

  void drive(string destination) const;
};
