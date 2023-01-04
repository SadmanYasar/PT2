#include "location.hpp"
#include <string>
#include "graphics.h"

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

class MovingObject
{
protected:
    int color;
    int speed;
    int size;
    Location *location;

public:
    MovingObject();
    int getSpeed() const;
    void setSpeed(int _speed);
    void move();

    int left() const { return location->getX() - size; }
    void left(int l) { location->setX(l + size); }
    int right() const { return location->getX() + size; }
    void right(int r) { location->setY(r + size); }

    int getColor() const { return color; }
    void setColor(int value) { color = value; }

    int getSize() const { return size; }
    void setSize(int value) { size = value; }

    void _draw(int c) const
    {
        setcolor(c);
        setfillstyle(SOLID_FILL, c);
        fillellipse(location->getX(), location->getY(), size, size);
    }

    void draw() const { _draw(color); }
    void undraw() const { _draw(BLACK); }

    void moveTo(int _x, int _y)
    {
        location->setLocation(_x, _y);
    }

    void moveBy(int dx, int dy)
    {
        // location->setLocation(location->getX() + dx, location->getY() + dy);
        location->setLocation(0, 0);
        // x += dx;
        // y += dy;
    }

    Location *getLocation()
    {
        return location;
    }
    ~MovingObject();
};

#endif
