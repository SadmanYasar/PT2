#ifndef BULLET_H
#define BULLET_H

#include <graphics.h>
#include "space_ship.hpp"

class SpaceShip;

class Bullet
{
  private:
	int x, y;
	int size;
	int color;
	int speed;
	bool active;
	SpaceShip *spaceShip;

	void drawHelper(int c) const;
  public:
	Bullet(int _x = 0, int _y = 0, int _size = 10, int _color = YELLOW, int _speed = 10);
	int getY() const;
	bool getActive() const;
	void setSpaceShip(SpaceShip *s);
	void draw() const;
	void undraw() const;
	void move();
	void reset();
};

#endif
