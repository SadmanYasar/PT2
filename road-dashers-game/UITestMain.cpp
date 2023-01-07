// Programming Technique II
// Semester 2, 2022/2023
// Road Dashers Game

#include <graphics.h>
#include <iostream>
#include "include/vehicle.hpp"
#include "include/location.hpp"
#include "include/ui.hpp"
#include "include/coin.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

#define COUNT 2

// Testing UI Class:
// This testing is to show how the UI class is manipulated

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "UI Test");

    srand(time(0));

    Location scoreLocation(screenWidth - 300, screenHeight / 2 - 300);
    UI score("", COLOR(255, 255, 0), 0, &scoreLocation);

    Location playerLocation(200, screenHeight / 2);
    Vehicle player("Player", COLOR(255, 0, 0), 50, &playerLocation);

    Location coinLocation(screenWidth + rand() % 701 + 200, screenHeight / 2);
    Coin coin("Coin", COLOR(10, 255, 0), 30, &coinLocation);

    while (true)
    {
        player.draw();
        coin.undraw();
        coin.moveBy(-30, 0);
        coin.draw();

        score.display();

        if (coin.getLocation()->getX() - player.getLocation()->getX() < 100 && coin.getLocation()->getX() - player.getLocation()->getX() > 0 && coin.getLocation()->getY() == player.getLocation()->getY())
        {
            coin.undraw();
            coin.moveTo(screenWidth + rand() % 701 + 200, screenHeight / 2);
            score.setValue(score.getValue() + 1);
        }

        delay(100);
    }

    return 0;
}