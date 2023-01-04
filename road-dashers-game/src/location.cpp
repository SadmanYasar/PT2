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

constructor()
{
    this.ui = new UI();
    this.movingObj = new movingObject();
    this.game = new Game();
}
