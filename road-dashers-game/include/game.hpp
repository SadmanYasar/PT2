#pragma once

class Game
{
protected:
    int width;
    int height;
    bool gameOver;

public:
    Game();
    int getWidth() const;
    int getHeight() const;
    void setWidth(int _width);
    void setHeight(int _height);
    bool isGameOver() const;
    void setGameOver(bool state);
};