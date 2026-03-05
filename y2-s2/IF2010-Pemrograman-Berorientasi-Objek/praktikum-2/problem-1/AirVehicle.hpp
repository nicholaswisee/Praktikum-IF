#include "Vehicle.hpp"
#include <iostream>
#include <string>

using namespace std;

class AirVehicle : private Vehicle {

protected:
  int maxAltitude;

public:
  AirVehicle(string vehicleId, string brand, int maxSpeed, int maxAltitude);
  ~AirVehicle();

  void fly(string destination);

  string getBrandName() const;
  string showSpec() const;
};
