#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Collider.hpp"
#include <string>
using namespace std;

class Obstacle : public Collider
{

public:
    Obstacle(int color = WHITE, int size = 100, Location *location = nullptr);
    void handleCollision(Player &player, UI &score, Game &gameManager);
};

#endif
