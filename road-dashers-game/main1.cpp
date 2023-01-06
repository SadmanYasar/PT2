#include <graphics.h>
#include <iostream>
#include "include/vehicle.hpp"
#include "include/location.hpp"
using namespace std;

#define MAX_MOVING_OBJECTS 5

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    char key = 0;

    initwindow(screenWidth, screenHeight, "Simple Animation");
    Location playerLocation(200, screenHeight / 2);

    Vehicle player("Player", COLOR(255, 0, 0), 10, 100, &playerLocation);

    player.draw();

    Location enemyLocation1(screenWidth - 100, screenHeight / 2 - 100);
    Location enemyLocation2(screenWidth - 100, screenHeight / 2 - 100);
    Location enemyLocation3(screenWidth - 100, screenHeight / 2 - 100);
    Location enemyLocation4(screenWidth - 100, screenHeight / 2 - 100);
    Location enemyLocation5(screenWidth - 100, screenHeight / 2 - 100);
    Vehicle movingObjects[MAX_MOVING_OBJECTS] = {
        Vehicle("Enemy", COLOR(10, 255, 0), 10, 80, &enemyLocation1),
        Vehicle("Enemy", COLOR(50, 255, 0), 10, 90, &enemyLocation2),
        Vehicle("Enemy", COLOR(100, 255, 0), 10, 60, &enemyLocation3),
        Vehicle("Enemy", COLOR(0, 255, 100), 10, 65, &enemyLocation4),
        Vehicle("Enemy", COLOR(0, 255, 200), 10, 70, &enemyLocation5),
    };

    // for (int i = 0; i < MAX_MOVING_OBJECTS; i++)
    // {
    //     movingObjects[i].setLocation(enemyLocation);
    // }

    // Location enemyLocation(screenWidth - 100, screenHeight / 2 - 100);
    // Vehicle enemy("Enemy", COLOR(0, 255, 0), 10, 80, &enemyLocation);
    // movingObjects[0].draw();
    while (key != 27) // 27 - Esc
    {
        // only spawn enemy if moving objects less than 5
        // if (MovingObject::getCount() < MAX_MOVING_OBJECTS)
        // {
        //     /*
        //     =============================================
        //     - spawn enemy
        //     - check if its x distance away from spawn point
        //     - if so, then spawn another enemy
        //     - after reaching the end, delete this enemy
        //     =============================================
        //      */
        //     Location enemyLocation(screenWidth - 100, screenHeight / 2 - 100);
        //     Vehicle enemy("Enemy", COLOR(0, 255, 0), 10, 80, &enemyLocation);
        //     enemy.draw();
        // }
        /*
        ===============================================
        Collision detection
            - check if enemy x < player.x + radius && enemy y == player y
            - if true then game over
            - else, carry on moving
        ===============================================
        */
        // Location enemyLocation(screenWidth - 100, screenHeight / 2 - 100);
        // Vehicle enemy("Enemy", COLOR(0, 255, 0), 10, 80, &enemyLocation);
        // movingObjects[2].draw();

        movingObjects[0].undraw();
        movingObjects[0].moveBy(-30, 0);
        movingObjects[0].draw();
        for (int i = 0; i < MAX_MOVING_OBJECTS - 1; i++)
        {
            if (movingObjects[i].getLocation()->getX() < player.getLocation()->getX() + 100 && movingObjects[i].getLocation()->getY() == player.getLocation()->getY())
            {
                // Game Over
                return 0;
            }

            int debugVal = movingObjects[i + 1].getLocation()->getX() - movingObjects[i].getLocation()->getX();

            // int debugVal = movingObjects[i].getLocation()->getX() - movingObjects[i + 1].getLocation()->getX();
            /* setcolor(12);
            settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
            bgiout << debugVal;
            outstreamxy(getmaxwidth() * 0.91, getmaxheight() * 0.1); */

            if (debugVal > 200)
            {
                movingObjects[i + 1].undraw();
                movingObjects[i + 1].moveTo(movingObjects[i].getLocation()->getX() + 400, movingObjects[i + 1].getLocation()->getY());
                movingObjects[i + 1].draw();
            }
        }

        delay(100);
        // TODO - if outside screen - remove enemy and create new one

        if (kbhit())
        {
            key = getch();

            if (key == 0) // special keys like arrow keys need to call to getch() twice.
                key = getch();

            switch (key)
            {
            case 72:
                // up
                player.undraw();
                player.moveTo(player.getLocation()->getX(), screenHeight / 2 - 100);
                player.draw();
                break;
            case 80:
                // down
                player.undraw();
                player.moveTo(player.getLocation()->getX(), screenHeight / 2 + 100);
                player.draw();
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
