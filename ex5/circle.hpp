#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

class Circle : public Shape
{
protected:
    int radius;

public:
    Circle(int _x = 0, int _y = 0, int _radius = 0);
    void draw() const;
    void undraw() const;
    void resize(double scale);
    bool isMouseClicked(int mx, int my) const;
};

#endif