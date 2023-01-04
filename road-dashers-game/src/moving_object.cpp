#include "include/moving_object.hpp"
#include <string>

string MovingObject::getColor() const
{
    return color;
}

void MovingObject::setColor(string _color)
{
    color = _color;
}

int MovingObject::getSpeed() const
{
    return speed;
}

void MovingObject::setSpeed(int _speed)
{
    speed = _speed;
}

void MovingObject::move()
{
    // TODO
}

MovingObject::MovingObject()
{
    // TODO
}

MovingObject::~MovingObject()
{
    delete location;
}
