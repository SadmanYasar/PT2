#include "include/enemy_vehicle.hpp"
#include "include/collider.hpp"
#include "include/player.hpp"
#include "include/ui.hpp"
#include "include/game.hpp"

EnemyVehicle::EnemyVehicle(int color, int size, Location *location) : Collider(color, size, location) {}

void EnemyVehicle::handleCollision(Player &player, UI &score, Game &gameManager)
{
    if (hasHitPlayer(player))
    {
        PlaySound(TEXT("assets/sounds/crash.wav"), NULL, SND_ASYNC);
        gameManager.setGameOver(true);
    }
}