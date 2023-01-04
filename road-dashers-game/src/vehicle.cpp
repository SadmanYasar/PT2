#include "vehicle.hpp"

Vehicle::Vehicle(string n) const
{
    name = n;
}

string Vehicle::getName() const
{
    return name;
}

void Vehicle::setName(string n)
{
    name = n;
}

~Vehicle() {}

// association
constructor()
{
    this.coins = [];
    this.obstaclesHit = [];
}

earn(coin)
{
    this.coins.push(coin);
}

hit(obstacle)
{
    this.obstaclesHit.push(obstacle);
}
