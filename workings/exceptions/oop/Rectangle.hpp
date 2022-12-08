#pragma once

class Rectangle
{
private:
    int x;
    int *ptrY;

public:
    class NegativeSize
    {
        // empty class declaration
    };

    Rectangle();
    Rectangle(const Rectangle &);

    int getX() const;
    void setX(int);

    int getY() const;
    void setY(int);

    int getArea() const;

    ~Rectangle();
};