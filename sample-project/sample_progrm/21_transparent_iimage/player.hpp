#pragma once

#include <graphics.h>
#include "image.hpp"

class Player
{
private:
    int left, top, width, height;
    Image image;
    int movement;

public:
    Player(int _left = 0, int _top = 0, int _width = 200, int _height = 220);

    void init();
    void draw();
    void undraw();
    void move();
    void reverse();

    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;
    int getHeight() const;
    int getMovement() const;

    void setLeft(int value);
    void setTop(int value);
    void setMovement(int value);
};