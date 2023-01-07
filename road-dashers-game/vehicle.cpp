#include "include/vehicle.hpp"
#include <string>
using namespace std;

Vehicle::Vehicle(string name, int color, int size, Location *location)
{
    this->name = name;
    this->color = color;
    this->size = size;
    this->location = location;
}