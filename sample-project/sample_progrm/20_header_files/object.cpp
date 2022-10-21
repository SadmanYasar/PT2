#include "include/system.hpp"

#include "include/object.hpp"

Object::Object(int _x, int _y, int _size, int _color, int _speed) : x(_x), y(_y), size(_size), color(_color), speed(_speed) {}

void Object::_draw(int col) const
{
    setcolor(col);
    setfillstyle(SOLID_FILL, col);
    _drawShape(); // This method is polymorphic. It needs to be overriden in the child classes, Square and Circle
}

void Object::draw() const { _draw(color); }

void Object::undraw() const { _draw(); }

void Object::move()
{
    undraw();
    if (x < getmaxx() - 50) // stops when reaching the right side of the screen
        x += speed;
    draw();
}
