#include "point.hpp"
#include "room.hpp"

#ifndef BALL_H
#define BALL_H

class Ball
{
private:
	Point location; // The center location. For specifing the location of the ball
	int size;		// For the dimension purposes
	int color;		// For appearance purposes
	int dx, dy;		// For movement purposes. The speed and direction

	Room *room;

public:
	Ball(Point _location = Point(0, 0), int _size = 50, int _color = 15, int _dx = 0, int _dy = 0);
	Ball(int _x = 0, int _y = 0, int _size = 50, int _color = 15, int _dx = 0, int _dy = 0);

	Point getLocation() const;
	int getSize() const;
	int getColor() const;
	int getDx() const;
	int getDy() const;
	int getLeft() const;   // To get the left most  x of the circle
	int getRight() const;  // To get the right most  x of the circle
	int getTop() const;	// To get the top most  y of the circle
	int getBottom() const; // To get the bottom most  y of the circle

	void setLocation(Point value);
	void setLocation(int x, int y);
	void setSize(int value);
	void setColor(int value);
	void setDx(int value);
	void setDy(int value);
	void setMovement(int _dx, int _dy);
	void set(Point _location, int _size, int _color, int _dx, int _dy);
	void setRoom(Room *_room);
	void setRandom();

	void draw() const;
	void undraw() const;
	void move();
};

#endif
