// Programming Technique II
// Semester 2, 2022/2023
// Road Dashers Game

#include <graphics.h>
#include <iostream>
#include "include/player.hpp"
#include "include/location.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

#define COUNT 2

// Testing Player Class:
// This testing is to show the player motion

// int main()
// {
//     int screenWidth = getmaxwidth();
//     int screenHeight = getmaxheight();
//     initwindow(screenWidth, screenHeight, "Vehicle Test");

//     srand(time(0));

//     Location location(screenWidth + rand() % 701 + 200, screenHeight / 2 - 100);

//     Player vehicle(COLOR(10, 255, 0), 100, &location);

//     while (true)
//     {
//         vehicle.undraw();
//         vehicle.moveBy(-50, 0);
//         vehicle.draw();

//         if (vehicle.getLocation()->getX() < 0)
//         {
//             vehicle.undraw();
//             // random number between 200 and 900
//             vehicle.moveTo(screenWidth + rand() % 701 + 200, location.getY());
//             vehicle.draw();
//         }
//         delay(100);
//     }

//     return 0;
// }