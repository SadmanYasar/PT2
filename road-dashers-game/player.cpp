#include "include/player.hpp"
#include <string>
using namespace std;

Player::Player(int color, int size, Location *location) : MovingObject(color, size, location) {}

void Player::move(int d)
{
    undraw();
    location->setY(d);
    draw();
}
