#pragma once

class Rectangle
{
private:
    int x;
    int *ptrY;

public:
    std::string negSize;
    class NegativeSize
    {
        // empty class declaration
        // for exception
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