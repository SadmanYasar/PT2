#pragma once

class Game
{
private:
    int width;
    int height;

public:
    int getWidth() const;
    int getHeight() const;
    void setWidth(int _width);
    void setHeight(int _height);
};