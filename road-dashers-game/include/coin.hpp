#ifndef COIN_H
#define COIN_H

#include "collider.hpp"
#include <string>
using namespace std;

class Coin : public Collider
{
private:
  int value;

public:
  Coin(int color = YELLOW, int size = 100, Location *location = nullptr, int val = 0);
  int getValue() const;
  void setValue(int v);
  void handleCollision(Player &player, UI &score, Game &gameManager);
};

#endif
