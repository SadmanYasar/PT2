#include "include/collider.hpp"
#include "include/moving_object.hpp"
#include "include/player.hpp"
#include <string>

Collider::Collider(int color, int size, Location *location) : MovingObject(color, size, location) {}

bool Collider::hasHitPlayer(Player &player)
{
    return (location->getX() - player.getLocation()->getX() < 100 && location->getX() - player.getLocation()->getX() > 0 && location->getY() == player.getLocation()->getY());
}

void Collider::move(int d)
{
    undraw();
    location->setX(location->getX() + d);
    draw();
}