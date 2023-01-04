#include "movingObject.hpp"

int Car::getColor() const
{
    return color;
}

void Car::setColor(string c)
{
    color = c;
}

int Car::getSpeed() const
{
    return speed;
}

void Car::setSpeed(int s)
{
    speed = s;
}

void Car::move()
{
}
