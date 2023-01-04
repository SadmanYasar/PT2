#include "moving_object.hpp"
#include <string>

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
