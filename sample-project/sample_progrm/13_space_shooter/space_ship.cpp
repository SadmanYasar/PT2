#include <graphics.h>
#include "space_ship.hpp"
#include "bullet.hpp"

SpaceShip::SpaceShip(int _x, int _y, int _width, int _height, int _color) : x(_x), y(_y),
                                                                            width(_width), height(_height),
                                                                            color(_color)
{
    bullets = new Bullet[MAXBULLET];
    for (int i = 0; i < MAXBULLET; i++)
        bullets[i].setSpaceShip(this);
}

int SpaceShip::getX() const { return x; }
int SpaceShip::getY() const { return y; }
int SpaceShip::getWidth() const { return width; }
int SpaceShip::getHeight() const { return height; }

void SpaceShip::shoot()
{
    int foundAt = -1;
    for (int i = 0; i < MAXBULLET; i++)
    {
        if (!bullets[i].getActive())
        {
            foundAt = i;
            break;
        }
    }

    if (foundAt != -1){
        bullets[foundAt].reset();
        bullets[foundAt].draw();
    }
}

void SpaceShip::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    bar(x, y, x + width, y + height);
}

void SpaceShip::draw() const { drawHelper(color); }
void SpaceShip::undraw() const { drawHelper(0); }
void SpaceShip::move(int dx)
{
    undraw();
    x += dx;
    draw();
}

void SpaceShip::doAction()
{
    for (int i = 0; i < MAXBULLET; i++)
        bullets[i].move();
}