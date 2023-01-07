#include "moving_object.hpp"
#include <string>
using namespace std;

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle : public MovingObject
{

public:
    Vehicle(string name = "", int color = WHITE, int size = 100, Location *location = nullptr)
    {
        this->name = name;
        this->color = color;
        this->size = size;
        this->location = location;
    }
};

#endif
