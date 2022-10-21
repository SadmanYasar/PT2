#include "include/system.hpp"

#include "include/object.hpp"
#include "include/circle.hpp"

Circle::Circle(int _x, int _y, int r, int _color, int _speed) : Object(_x, _y, r, _color, _speed) {}

void Circle::_drawShape() const { fillellipse(x, y, size, size); }
