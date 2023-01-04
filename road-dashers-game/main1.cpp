#include <graphics.h>
#include <iostream>
#include "vehicle.hpp"
#include "location.hpp"
using namespace std;

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    char key = 0;

    initwindow(screenWidth, screenHeight, "Simple Animation");
    Location playerLocation(200, screenHeight / 2);

    Vehicle player("Player", COLOR(255, 0, 0), 10, 100, &playerLocation);

    player.draw();

    Location enemyLocation(screenWidth - 100, screenHeight / 2);
    Vehicle enemy("Enemy", COLOR(0, 255, 0), 10, 100, &enemyLocation);
    enemy.draw();
    while (key != 27) // 27 is the ASCII code for key Esc
    {
        enemy.moveBy(enemy.getLocation()->getX() - 10, 0);
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
