#include "include/moving_object.hpp"
#include <string>

MovingObject::MovingObject(int _color, int _size, Location *_location) : color(_color), size(_size), location(_location) {}

MovingObject::~MovingObject()
{
    location = nullptr;
}

// int MovingObject::left() const
// {
//     return location->getX() - size;
// }
// void MovingObject::left(int l)
// {
//     location->setX(l + size);
// }
// int MovingObject::right() const
// {
//     return location->getX() + size;
// }
// void MovingObject::right(int r)
// {
//     location->setY(r + size);
// }

int MovingObject::getColor() const
{
    return color;
}
void MovingObject::setColor(int value)
{
    color = value;
}

int MovingObject::getSize() const
{
    return size;
}
void MovingObject::setSize(int value)
{
    size = value;
}

void MovingObject::_draw(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(location->getX(), location->getY(), size, size);
}

void MovingObject::draw() const
{
    _draw(color);
}
void MovingObject::undraw() const
{
    _draw(BLACK);
}

void MovingObject::moveTo(int _x, int _y)
{
    location->setLocation(_x, _y);
}

void MovingObject::moveBy(int dx, int dy)
{
    location->setLocation(location->getX() + dx, location->getY() + dy);
}

Location *MovingObject::getLocation()
{
    return location;
}

void MovingObject::setLocation(Location &_location)
{
    *location = _location;
}
