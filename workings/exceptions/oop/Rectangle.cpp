#include <iostream>
#include "Rectangle.hpp"
using namespace std;

int Rectangle::getX() const { return x; }

void Rectangle::setX(int _x)
{
    if (_x < 0)
    {
        // this instantiates an object
        throw NegativeSize();
    }

    x = _x;
}

int Rectangle::getY() const { return *ptrY; }

void Rectangle::setY(int _y)
{
    if (_y < 0)
    {
        throw NegativeSize();
    }

    *ptrY = _y;
}

Rectangle::Rectangle()
{
    x = 0;
    ptrY = new int;
    cout << "Constructor Rectangle called" << endl;
}

// COPY CONSTRUCTOR
Rectangle::Rectangle(const Rectangle &obj)
{
    cout << "Copying in progress" << endl;
    ptrY = new int;
    *ptrY = obj.getY();
    cout << "Done!" << endl;
}

Rectangle::~Rectangle()
{
    delete ptrY;
    cout << "Destructor Rectangle called" << endl;
}

int Rectangle::getArea() const
{
    return x * *ptrY;
}