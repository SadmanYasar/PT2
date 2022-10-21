#ifndef CIRCLE_H
#define CIRCLE_H

#include "system.hpp"

#include "object.hpp"

class Circle : public Object
{
private:
	void _drawShape() const; // to be overriden as the parent's is pure virtual method

public:
	Circle(int _x = 0, int _y = 0, int r = 50, int _color = YELLOW, int _speed = 25);
};

#endif
