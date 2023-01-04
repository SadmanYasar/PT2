#include "include/location.hpp"

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

Location::Location()
{
    // this.ui = new UI();
    // this.movingObj = new movingObject();
    // this.game = new Game();
    x = 0;
    y = 0;
}

void Location::setLocation(int x, int y)
{
    this->x = x;
    this->y = y;
}