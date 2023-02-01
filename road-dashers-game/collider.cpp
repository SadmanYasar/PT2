#include "include/collider.hpp"
#include "include/moving_object.hpp"
#include "include/player.hpp"
#include "include/game.hpp"
#include <string>

Collider::Collider(int color, int size, Location *location) : MovingObject(color, size, location) {}

bool Collider::hasHitPlayer(Player &player)
{
    // if dx 0 to 100
    // & player y == collider y
    return (location->getX() - player.getLocation()->getX() < 100 && location->getX() - player.getLocation()->getX() > 0 && location->getY() == player.getLocation()->getY());
}

void Collider::move(int d)
{
    undraw();
    location->setX(location->getX() + d);
    draw();
}

void Collider::relocateCollider(Collider *collider, int w, Game gameManager)
{
    if (collider->getLocation()->getX() < 0)
    {
        int side = rand() % 2;
        collider->undraw();
        // random number between 200 and 900
        collider->moveTo(w + rand() % 701 + 200, side == 0 ? gameManager.getHeight() / 2 + 100 : gameManager.getHeight() / 2 - 100); // 701 = 900 - 200 + 1
        collider->draw();
    }
}
