#include <graphics.h>
#include <iostream>
#include "include/vehicle.hpp"
#include "include/location.hpp"
#include "include/moving_object.hpp"
#include "include/game.hpp"
#include "include/coin.hpp"
#include "include/ui.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_MOVING_OBJECTS 5

int main()
{
    bool gameOver = false;
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    char key = 0;

    srand(time(0));

    Location scoreLocation(screenWidth - 300, screenHeight / 2 - 300);
    UI score("", COLOR(255, 255, 0), 0, &scoreLocation);

    Location playerLocation(200, screenHeight / 2);
    Vehicle player("Player", COLOR(255, 0, 0), 40, &playerLocation);

    // player.draw();

    Location locations[MAX_MOVING_OBJECTS] = {
        Location(screenWidth + rand() % 1001 + 200, screenHeight / 2 - 100),
        Location(screenWidth + rand() % 1001 + 200, screenHeight / 2 + 100),
        Location(screenWidth + rand() % 1001 + 200, screenHeight / 2 - 100),
        Location(screenWidth + rand() % 1001 + 200, screenHeight / 2 + 100),
        Location(screenWidth + rand() % 1001 + 200, screenHeight / 2 - 100),
    };

    MovingObject movingObjects[MAX_MOVING_OBJECTS] = {
        Vehicle("Enemy", COLOR(10, 255, 0), 40, &locations[0]),
        Vehicle("Enemy", COLOR(10, 255, 0), 40, &locations[1]),
        Coin("Coin", YELLOW, 30, &locations[2]),
        Coin("Coin", YELLOW, 30, &locations[3]),
        Vehicle("Enemy", COLOR(10, 255, 0), 40, &locations[4]),
    };

    score.setText("YOUR SCORE");

    initwindow(screenWidth, screenHeight, "Road Rashers");

    readimagefile("assets/images/menu2.jpg", 0, 0, screenWidth, screenHeight);
    // main menu screen
    while (true)
    {
        if (kbhit())
        {
            PlaySound(TEXT("assets/sounds/collectcoin.wav"), NULL, SND_ASYNC);
            closegraph();
            break;
        }
    }

    initwindow(screenWidth, screenHeight, "GAME");

    while (key != 27) // 27 - Esc
    {
        player.draw();

        for (int i = 0; i < MAX_MOVING_OBJECTS - 1; i++)
        {
            if (movingObjects[i].getLocation()->getX() - player.getLocation()->getX() < 100 && movingObjects[i].getLocation()->getX() - player.getLocation()->getX() > 0 && movingObjects[i].getLocation()->getY() == player.getLocation()->getY())
            {
                string name = movingObjects[i].getName();
                // compare by name
                if (name == "Enemy")
                {
                    PlaySound(TEXT("assets/sounds/crash.wav"), NULL, SND_ASYNC);
                    gameOver = true;
                    break;
                }
                else if (name == "Coin")
                {
                    PlaySound(TEXT("assets/sounds/collectcoin.wav"), NULL, SND_ASYNC);
                    movingObjects[i].undraw();
                    movingObjects[i].moveTo(screenWidth + rand() % 701 + 200, locations[i].getY());
                    score.setValue(score.getValue() + 1);
                }
            }

            movingObjects[i].undraw();
            movingObjects[i].moveBy(-30, 0);
            movingObjects[i].draw();

            score.display();

            if (movingObjects[i].getLocation()->getX() < 0)
            {
                movingObjects[i].undraw();
                // random number between 200 and 900
                movingObjects[i].moveTo(screenWidth + rand() % 701 + 200, locations[i].getY()); // 701 = 900 - 200 + 1
                movingObjects[i].draw();
            }
        }

        if (gameOver)
        {
            Location gameOverLocation(screenWidth / 2, screenHeight / 2);
            UI gameOverText("GAME OVER!", COLOR(255, 255, 0), 0, &gameOverLocation);
            gameOverText.display();
            while (true)
            {
                if (kbhit())
                {
                    return 0;
                }
            }
        }
        delay(100);

        if (kbhit())
        {
            key = getch();

            if (key == 0) // special keys like arrow keys need to call to getch() twice.
                key = getch();

            switch (toupper(key))
            {
            case 'W':
                // up
                player.undraw();
                player.moveTo(player.getLocation()->getX(), screenHeight / 2 - 100);
                player.draw();
                break;
            case 'S':
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
