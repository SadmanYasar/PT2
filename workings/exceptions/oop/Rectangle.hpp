#pragma once

class Rectangle
{
private:
    int x;
    int *ptrY;

public:
    Rectangle();
    Rectangle(const Rectangle &);

    int getX() const;
    void setX(int);

    int getY() const;
    void setY(int);

    ~Rectangle();
};