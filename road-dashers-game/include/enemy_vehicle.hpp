#ifndef ENEMYVEHICLE_H
#define ENEMYVEHICLE_H

#include "collider.hpp"
#include "player.hpp"
#include "ui.hpp"
#include "game.hpp"
#include <string>
using namespace std;

class EnemyVehicle : public Collider
{

public:
    EnemyVehicle(int color = WHITE, int size = 100, Location *location = nullptr);
    void handleCollision(Player &player, UI &score, Game &gameManager);
};

#endif
