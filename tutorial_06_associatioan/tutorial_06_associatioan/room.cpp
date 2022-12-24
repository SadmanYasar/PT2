#include "room.hpp"
#include <graphics.h>

// Task 4:
//    Declaration and definition for this class have been given.
//    Review all the methods of this class.

Room::Room(int _x, int _y, int _width, int _height, int _color)
{
	set(_x, _y, _width, _height, _color);
}

int Room::getX() const { return x; }
int Room::getY() const { return y; }
int Room::getWidth() const { return width; }
int Room::getHeight() const { return height; }
int Room::getColor() const { return color; }
int Room::getRight() const { return x + width; }
int Room::getBottom() const { return y + height; }

void Room::setX(int value) { x = value; }
void Room::setY(int value) { y = value; }
void Room::setWidth(int value) { width = value; }
void Room::setHeight(int value) { height = value; }
void Room::setSize(int _width, int _height)
{
	width = _width;
	height = _height;
}
void Room::setColor(int value) { color = value; }
void Room::set(int _x, int _y, int _width, int _height, int _color)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	color = _color;
}

void Room::draw() const
{
	setfillstyle(SOLID_FILL,color);
	bar(x,y,x+width, y+height);
}
