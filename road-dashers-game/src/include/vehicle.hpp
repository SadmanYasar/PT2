#include "moving_object.hpp"

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle extends MovingObject
{
private:
    string name;
    // Coin *coin;

public:
    Vehicle(int _x, int _y, int _size, int _color = WHITE) : x(_x), y(_y), size(_size), color(_color) {}
    string getName() const;
    void setName(string n);
    void draw();
    ~Vehicle();
    // myVehicle.earn(myCoin);
    // myVehicle.hit(myObstacle);
};

#endif
