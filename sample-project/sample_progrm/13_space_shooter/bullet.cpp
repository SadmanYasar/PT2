#include <graphics.h>
#include "bullet.hpp"
#include "space_ship.hpp"

Bullet::Bullet(int _x, int _y, int _size, int _color, int _speed) : x(_x), y(_y),
                                                                    size(_size), color(_color),
                                                                    speed(_speed),
                                                                    spaceShip(NULL),
                                                                    active(false)
{
}

int Bullet::getY() const { return y; }
bool Bullet::getActive() const { return active; }
void Bullet::setSpaceShip(SpaceShip *s) { spaceShip = s; }

void Bullet::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(x, y, size, size);
}

void Bullet::draw() const { drawHelper(color); }
void Bullet::undraw() const { drawHelper(0); }

void Bullet::move()
{
    if (!active)
        return;
    undraw();
    y -= speed;

    if (y > 0)
        draw();
    else
        active = false;
}

void Bullet::reset()
{
    x = spaceShip->getX() + spaceShip->getWidth() / 2;
    y = spaceShip->getY() - size;
    active = true;
}
