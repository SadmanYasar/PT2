#include <graphics.h>
#include <cmath>
#include "shape.hpp"
#include "circle.hpp"

Circle::Circle(int _x, int _y, int _radius) : radius(_radius), Shape(_x, _y) {}

void Circle::draw() const
{
    setcolor(selected ? YELLOW : WHITE);
    circle(x, y, radius);
}

void Circle::undraw() const
{
    setcolor(BLACK);
    circle(x, y, radius);
}
void Circle::resize(double scale)
{
    if (!selected)
        return;

    undraw();
    radius *= scale;
    draw();
}
bool Circle::isMouseClicked(int mx, int my) const
{
    return (sqrt(pow(mx - x, 2) + pow(my - y, 2)) <= radius) ? true : false;
}
