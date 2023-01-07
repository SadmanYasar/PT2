#include "include/game.hpp"

int Game::getWidth() const { return width; }
int Game::getHeight() const { return height; }

void Game::setWidth(int _width) { width = _width; }
void Game::setHeight(int _height) { height = _height; }

/* bool Game::isGameOver()
{
    if (!gameOver)
    {
        return false;
    }

    return true;
}

void Game::setGameOver(bool val)
{
    gameOver = val;
} */
