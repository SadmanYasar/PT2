#include "moving_object.hpp"
#include <string>
using namespace std;

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle : public MovingObject
{
private:
    string name;
    // Coin *coin;

public:
    // Vehicle(int _x, int _y, int _size, int _color = WHITE) : x(_x), y(_y), size(_size), color(_color) {}
    Vehicle(string name = "", int color = WHITE, int speed = 1, int size = 100, Location *location = nullptr)
    {
        this->name = name;
        this->color = color;
        this->speed = speed;
        this->size = size;
        this->location = location;
    }
    string getName() const;
    void setName(string n);
    // void draw();
    // ~Vehicle();
    // myVehicle.earn(myCoin);
    // myVehicle.hit(myObstacle);
};

#endif
