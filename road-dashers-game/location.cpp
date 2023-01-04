#include "location.hpp"

int Location::getX() const
{
    return x;
}

void Location::setX(int _x)
{
    x = _x;
}

int Location::getY() const
{
    return y;
}

void Location::setY(int _y)
{
    y = _y;
}

Location::Location(int x = 0; int y = 0)
{
    this->x = x;
    this->y = y;
}

void Location::setLocation(int x, int y)
{
    this->x = x;
    this->y = y;
}