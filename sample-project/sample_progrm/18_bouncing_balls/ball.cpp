#include <graphics.h>
#include <cstdlib>

#include "point.hpp"
#include "ball.hpp"

Ball::Ball(Point _location, int _size, int _color, int _dx, int _dy) : room(NULL)
{
	set(_location, _size, _color, _dx, _dy);
}

Ball::Ball(int _x, int _y, int _size, int _color, int _dx, int _dy) : Ball(Point(_x, _y), _size, _color, _dx, _dy)
{
}

Point Ball::getLocation() const { return location; }
int Ball::getSize() const { return size; }
int Ball::getColor() const { return color; }
int Ball::getDx() const { return dx; }
int Ball::getDy() const { return dy; }
int Ball::getLeft() const { return location.getX() - size; }
int Ball::getRight() const { return location.getX() + size; }
int Ball::getTop() const { return location.getY() - size; }
int Ball::getBottom() const { return location.getY() + size; }

void Ball::setLocation(Point value) { location = value; }
void Ball::setLocation(int x, int y) { location.set(x, y); }
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

void Ball::setRoom(Room *_room) { room = _room; }

// void Ball::setX(int value) { location.setX(value); }
// void Ball::setY(int value) { location.setY(value); }

void Ball::draw() const
{
	setcolor(color);
	circle(location.getX(), location.getY(), size);
}

void Ball::undraw() const
{
	setcolor(room->getColor()); // draw the ball with the background color
	circle(location.getX(), location.getY(), size);
}

void Ball::move()
{
	undraw();

	location.move(dx, dy);

	// Change the direction of the movement when the ball reaches the room's borders
	if (getRight() >= room->getRight())
	{
		dx = -dx;
		location.setX(room->getRight() - size); // correction if the ball moves beyond the right border of the room
	}
	else if (getLeft() <= room->getX())
	{
		dx = -dx;
		location.setX(room->getX() + size); // correction if the ball moves beyond the left border of the room
	}

	if (getBottom() >= room->getBottom())
	{
		dy = -dy;
		location.setY(room->getBottom() - size); // correction if the ball moves beyond the bottom border of the room
	}
	else if (getTop() <= room->getY())
	{
		dy = -dy;
		location.setY(room->getY() + size); // correction if the ball moves beyond the top border of the room
	}

	draw();
}

void Ball::setRandom()
{
	int max_r = 0.1 * room->getWidth();
	int r = rand() % max_r + 5;
	int x = room->getX() + rand() % room->getWidth() + r;
	int y = room->getY() + rand() % room->getHeight() + r;
	int _dx = rand() % max_r + 10;
	int _dy = rand() % max_r + 10;

	if (rand() % 10 < 5)
		_dx = -_dx;
	if (rand() % 10 < 5)
		_dy = -_dy;

	set(Point(x, y), r, rand() % 15 + 1, _dx, _dy);
}