#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include <graphics.h>
#include "bullet.hpp"

#define MAXBULLET 10

class Bullet;

class SpaceShip
{
private:
	int x, y;
	int width, height;
	int color;

	Bullet *bullets;

	void drawHelper(int c) const;

public:
	SpaceShip(int _x = 0, int _y = 0, int _width = 150, int _height = 100, int _color = BLUE);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	void shoot();
	void draw() const;
	void undraw() const;
	void move(int dx);
	void doAction();
};

#endif
