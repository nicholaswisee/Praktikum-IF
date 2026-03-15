#include "Vehicle.hpp"
#include <iostream>
#include <string>

class WaterVehicle : protected Vehicle {

protected:
  int displacement;

public:
  WaterVehicle(string vehicleId, string brand, int maxSpeed, int displacement);
  ~WaterVehicle();

  int getDisplacement() const;

  void sail(string destionation) const;

  string showSpec() const;
};
