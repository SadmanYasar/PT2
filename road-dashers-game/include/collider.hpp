#pragma once
#include "moving_object.hpp"
#include "player.hpp"
#include "ui.hpp"
#include "game.hpp"
#include <string>
using namespace std;

class Collider : public MovingObject
{

public:
    Collider(int color = WHITE, int size = 100, Location *location = nullptr);
    void move(int d);
    bool hasHitPlayer(Player &player);
    virtual void handleCollision(Player &player, UI &score, Game &gameManager) = 0;
    void relocateCollider(Collider *collider, int w);
};