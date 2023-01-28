#include "include/coin.hpp"
#include "include/moving_object.hpp"

Coin::Coin(string _name, int _color, int _size, Location *_location, int _value) : MovingObject(_name, _color, _size, _location), value(_value) {}

int Coin::getValue() const
{
    return value;
}

void Coin::setValue(int v)
{
    value = v;
}
