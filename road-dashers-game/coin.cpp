#include "include/coin.hpp"

Coin::Coin(int v)
{
    value = v;
}

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
