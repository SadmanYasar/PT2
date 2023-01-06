#include "moving_object.hpp"

#ifndef COIN_H
#define COIN_H

class Coin : public MovingObject
{
private:
  int value;

public:
  Coin(int v);
  int getValue() const;
  void setValue(int v);
  ~Coin();
};

#endif
