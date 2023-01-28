#include "moving_object.hpp"
#include <string>
using namespace std;

#ifndef COIN_H
#define COIN_H

class Coin : public MovingObject
{
private:
  int value;

public:
  Coin(string name = "", int color = YELLOW, int size = 100, Location *location = nullptr, int val = 0);
  int getValue() const;
  void setValue(int v);
};

#endif
