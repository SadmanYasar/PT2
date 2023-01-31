#include "location.hpp"
#include <string>
#include <graphics.h>
using namespace std;

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

class MovingObject
{

protected:
    int color;
    int size;
    Location *location;

public:
    MovingObject(int color = YELLOW, int size = 100, Location *location = nullptr);

    // int left() const;
    // void left(int l);
    // int right() const;
    // void right(int r);

    int getColor() const;
    void setColor(int value);

    int getSize() const;
    void setSize(int value);

    void _draw(int c) const;

    void draw() const;
    void undraw() const;

    void moveTo(int _x, int _y);

    void moveBy(int dx, int dy);

    Location *getLocation();
    void setLocation(Location &_location);

    virtual void move(int d) = 0;

    ~MovingObject();
};

#endif
