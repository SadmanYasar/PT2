#include "location.hpp"
#include <string>
#include "graphics.h"
using namespace std;

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

class MovingObject
{

protected:
    string name;
    int color;
    // int speed;
    int size;
    Location *location;

public:
    MovingObject();
    // int getSpeed() const;
    // void setSpeed(int _speed);

    int left() const;
    void left(int l);
    int right() const;
    void right(int r);

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

    string getName() const;
    void setName(string n);

    ~MovingObject();
};

#endif
