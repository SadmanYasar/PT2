#include <graphics.h>
#include "point.hpp"
#include "ball.hpp"

// Task 3:
//    The definition code of some methods of this class have been given.
//    Complete the rest accordingly.

// The definition for this constructor has been given.
// Review the code.
Ball::Ball(Point _location, int _size, int _color, int _dx, int _dy)
{
	set(_location, _size, _color, _dx, _dy);
}

// ! Complete this constructor - DONE
Ball::Ball(int _x, int _y, int _size, int _color, int _dx, int _dy) : Ball(Point(_x, _y), _size, _color, _dx, _dy)
{
}

// The defintions of some of the methods have been given.
// Review the code.
Point Ball::getLocation() const { return location; }
int Ball::getSize() const { return size; }
int Ball::getColor() const { return color; }
int Ball::getDx() const { return dx; }
int Ball::getDy() const { return dy; }

int Ball::getLeft() const
{
	return location.getX() - size;
}

//! Complete the following methods - DONE
int Ball::getRight() const
{
	return location.getX() + size;
}

int Ball::getTop() const
{
	return location.getY() - size;
}

int Ball::getBottom() const
{
	return location.getY() + size;
}

// The defintions of the following  methods have been given.
// Review the code.
void Ball::setSize(int value) { size = value; }
void Ball::setColor(int value) { color = value; }
void Ball::setDx(int value) { dx = value; }
void Ball::setDy(int value) { dy = value; }
void Ball::setMovement(int _dx, int _dy)
{
	dx = _dx;
	dy = _dy;
}
void Ball::set(Point _location, int _size, int _color, int _dx, int _dy)
{
	location = _location;
	size = _size;
	color = _color;
	dx = _dx;
	dy = _dy;
}

void Ball::setLocation(Point value)
{
	location = value;
}

//! Complete the following method - DONE
void Ball::setLocation(int x, int y)
{
	location.set(x, y);
}

// The defintion of the following method has been given.
// Review the code, especially how to get the coordinate x and y of the ball
void Ball::draw() const
{
	setcolor(color);
	circle(location.getX(), location.getY(), size);
}

void Ball::undraw() const
{
	setcolor(0); // to draw the ball with the background color
	circle(location.getX(), location.getY(), size);
}

// The defintion of the following method has been partially given.
// Review the code

void Ball::move()
{
	undraw();
	location.move(dx, dy);

	// Test for collission with the wall of the room where this ball lives
	// If it collides, change its direction of movement

	draw();
}
