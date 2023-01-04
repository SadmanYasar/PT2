#include "moving_object.hpp"

#ifndef COIN_H
#define COIN_H

class Coin extends MovingObject
{
private:
  int value;

public:
  Coin();
  int getValue() const;
  void setValue(int v);
  ~Coin();
};

#endif
