#include "include/obstacle.hpp"
#include "include/collider.hpp"
#include "include/player.hpp"
#include "include/ui.hpp"
#include "include/game.hpp"

Obstacle::Obstacle(int color, int size, Location *location) : Collider(color, size, location) {}

void Obstacle::handleCollision(Player &player, UI &score, Game &gameManager)
{
    if (hasHitPlayer(player))
    {
        PlaySound(TEXT("assets/sounds/crash.wav"), NULL, SND_ASYNC);
        undraw();
        moveTo(gameManager.getWidth() + rand() % 701 + 200, player.getLocation()->getY());
        score.setValue(score.getValue() - 1);
    }
}