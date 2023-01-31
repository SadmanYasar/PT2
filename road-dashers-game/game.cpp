#include "include/game.hpp"
#include <graphics.h>

Game::Game()
{
    this->gameOver = false;
    this->width = getmaxwidth();
    this->height = getmaxheight();
}

int Game::getWidth() const
{
    return width;
}
int Game::getHeight() const { return height; }

void Game::setWidth(int _width) { width = _width; }
void Game::setHeight(int _height) { height = _height; }

bool Game::isGameOver() const { return gameOver; }
void Game::setGameOver(bool state) { gameOver = state; }
