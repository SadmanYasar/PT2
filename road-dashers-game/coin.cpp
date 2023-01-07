#include "include/coin.hpp"


int Coin::getValue() const
{
    return value;
}

void Coin::setValue(int v)
{
    value = v;
}

Coin::~Coin()
{
}
