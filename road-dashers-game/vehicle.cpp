#include "include/vehicle.hpp"
#include <string>
using namespace std;

/* Vehicle::Vehicle(string n)
{
    name = n;
} */

string Vehicle::getName() const
{
    return name;
}

void Vehicle::setName(string n)
{
    name = n;
}

// ~Vehicle() {}

// association
/* constructor()
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
 */