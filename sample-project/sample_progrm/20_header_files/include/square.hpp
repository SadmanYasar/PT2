#ifndef SQUARE_H
#define SQUARE_H

#include "system.hpp"

class Square : public Object
{
private:
	void _drawShape() const; // to be overriden as the parent's is pure virtual method

public:
	Square(int _x = 0, int _y = 0, int w = 100, int _color = GREEN, int _speed = 50);
};

#endif
