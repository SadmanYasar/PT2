#include "include/system.hpp"

#include "include/object.hpp"
#include "include/square.hpp"

Square::Square(int _x, int _y, int w, int _color, int _speed) : Object(_x, _y, w, _color, _speed) {}
void Square::_drawShape() const { bar(x, y, x + size, y + size); }
