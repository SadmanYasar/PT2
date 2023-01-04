#include "obstacle.hpp"

// TODO - FIX THIS CODE

Obstacle obs;
cout << obs.getType() << endl; // prints an empty string
obs.setType("rock");
cout << obs.getType() << endl; // prints "rock"

Obstacle obs2("tree");
cout << obs2.getType() << endl; // prints "tree"