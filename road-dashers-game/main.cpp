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

void checkIfGameOver(Game &gameManager)
{
    if (gameManager.isGameOver())
    {
        Location gameOverLocation(gameManager.getWidth() / 2, gameManager.getHeight() / 2);
        UI gameOverText("GAME OVER!", COLOR(255, 255, 0), 0, &gameOverLocation);
        gameOverText.display();
        while (true)
        {
            if (kbhit())
            {
                return;
            }
        }
    }
}

void initMenu(Game &gameManager)
{
    int width = gameManager.getWidth();
    int height = gameManager.getHeight();
    initwindow(width, height, "Road Rashers");

    readimagefile("assets/images/menu2.jpg", 0, 0, width, height);
    while (true)
    {
        if (kbhit())
        {
            PlaySound(TEXT("assets/sounds/collectcoin.wav"), NULL, SND_ASYNC);
            closegraph();
            break;
        }
    }
}

// TODO - PLAYER, COIN, OBSTACLE inherit from MOVING OBJECT
/*
   - these classes will have move (polymorphic),
   - coin, obstacle will inherit from one class that inherits from moving object
   - coin, obstacle will have speedFactor
   - coin, obstacle will have collide(polymorphic)
   - Replace shapes with images
*/
int main()
{
    Game gameManager;
    char key = 0;

    srand(time(NULL));

    initMenu(gameManager);

    Location scoreLocation(gameManager.getWidth() - 300, gameManager.getHeight() / 2 - 300);
    UI score("", COLOR(255, 255, 0), 0, &scoreLocation);
    score.setText("YOUR SCORE");

    Location playerLocation(200, gameManager.getHeight() / 2);
    Vehicle player("Player", COLOR(255, 0, 0), 40, &playerLocation);

    Location locations[MAX_MOVING_OBJECTS] = {
        Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 - 100),
        Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 + 100),
        Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 - 100),
        Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 + 100),
        Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 - 100),
    };

    MovingObject movingObjects[MAX_MOVING_OBJECTS] = {
        Vehicle("Enemy", COLOR(10, 255, 0), 40, &locations[0]),
        Vehicle("Enemy", COLOR(10, 255, 0), 40, &locations[1]),
        Coin("Coin", YELLOW, 30, &locations[2]),
        Coin("Coin", YELLOW, 30, &locations[3]),
        Vehicle("Enemy", COLOR(10, 255, 0), 40, &locations[4]),
    };

    initwindow(gameManager.getWidth(), gameManager.getHeight(), "GAME");

    do
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
                    gameManager.setGameOver(true);
                    break;
                }
                else if (name == "Coin")
                {
                    PlaySound(TEXT("assets/sounds/collectcoin.wav"), NULL, SND_ASYNC);
                    movingObjects[i].undraw();
                    movingObjects[i].moveTo(gameManager.getWidth() + rand() % 701 + 200, locations[i].getY());
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
                movingObjects[i].moveTo(gameManager.getWidth() + rand() % 701 + 200, locations[i].getY()); // 701 = 900 - 200 + 1
                movingObjects[i].draw();
            }
        }

        checkIfGameOver(gameManager);
        delay(100);

        if (kbhit() && gameManager.isGameOver() == false)
        {
            key = getch();

            if (key == 0) // special keys like arrow keys need to call to getch() twice.
                key = getch();

            switch (toupper(key))
            {
            case 'W':
                // up
                player.undraw();
                player.moveTo(player.getLocation()->getX(), gameManager.getHeight() / 2 - 100);
                player.draw();
                break;
            case 'S':
                // down
                player.undraw();
                player.moveTo(player.getLocation()->getX(), gameManager.getHeight() / 2 + 100);
                player.draw();
                break;
            default:
                break;
            }
        }
    } while (gameManager.isGameOver() == false);

    return 0;
}
