#ifndef PLAYER_H
#define PLAYER_H

#include "moving_object.hpp"
#include <string>
using namespace std;

class Player : public MovingObject
{

public:
    void move(int d);
    Player(int color = WHITE, int size = 100, Location *location = nullptr);
};

#endif
