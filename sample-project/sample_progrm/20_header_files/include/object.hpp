#ifndef OBJECT_H
#define OBJECT_H

#include "system.hpp"

class Object
{
protected:
	int x, y;
	int size;
	int color;
	int speed;

	virtual void _drawShape() const = 0; // only this method is different between drawing the square and circle. Thus, make it virtual
	void _draw(int col = BLACK) const;

public:
	Object(int _x = 0, int _y = 0, int _size = 50, int _color = WHITE, int _speed = 0);
	void draw() const;
	void undraw() const;
	void move();
};

#endif
