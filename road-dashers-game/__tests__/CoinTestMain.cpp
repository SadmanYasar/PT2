// Programming Technique II
// Semester 2, 2022/2023
// Road Dashers Game

#include <graphics.h>
#include <iostream>
#include "include/coin.hpp"
#include "include/location.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

#define COUNT 2

// Testing Coin Class:
// This testing is to show the coin's motion

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Vehicle Test");

    srand(time(0));

    Location location(screenWidth + rand() % 701 + 200, screenHeight / 2 - 100);

    Coin coin(YELLOW, 100, &location);

    while (true)
    {
        coin.move(-50);
        coin.relocateCollider(&coin, screenWidth);
        delay(100);
    }

    return 0;
}