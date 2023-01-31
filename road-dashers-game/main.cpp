#include <graphics.h>
#include <iostream>
#include "include/player.hpp"
#include "include/collider.hpp"
#include "include/enemy_vehicle.hpp"
#include "include/obstacle.hpp"
#include "include/location.hpp"
#include "include/game.hpp"
#include "include/coin.hpp"
#include "include/ui.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

#define MAX_MOVING_OBJECTS 6

Location *locations[MAX_MOVING_OBJECTS];
Collider *colliders[MAX_MOVING_OBJECTS];

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

void initMenu()
{
    int width = getmaxwidth();
    int height = getmaxheight();
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

void game()
{
    Game gameManager;

    char key = 0;

    srand(time(0));

    generateLocations(gameManager);
    generateColliders();

    Location scoreLocation(gameManager.getWidth() - 300, gameManager.getHeight() / 2 - 300);
    UI score("", COLOR(255, 255, 0), 0, &scoreLocation);
    score.setText("YOUR SCORE");

    Location playerLocation(200, gameManager.getHeight() / 2);
    Player player(COLOR(255, 0, 0), 40, &playerLocation);

    initwindow(gameManager.getWidth(), gameManager.getHeight(), "GAME");

    do
    {
        score.display();

        player.draw();

        for (int i = 0; i < MAX_MOVING_OBJECTS - 1; i++)
        {
            colliders[i]->handleCollision(player, score, gameManager);

            colliders[i]->move(-30);

            relocateCollider(colliders[i], gameManager.getWidth());
        }

        handleOverLap();

        checkIfGameOver(gameManager);
        delay(100);

        if (kbhit() && gameManager.isGameOver() == false)
        {
            key = getch();

            switch (toupper(key))
            {
            case 'W':
                player.move(gameManager.getHeight() / 2 - 100);
                break;
            case 'S':
                player.move(gameManager.getHeight() / 2 + 100);
                break;
            default:
                break;
            }
        }
    } while (gameManager.isGameOver() == false);
}

void generateLocations(Game &gameManager)
{
    for (int i = 0; i < MAX_MOVING_OBJECTS; i++)
    {
        int side = rand() % 2;
        if (side == 0)
        {
            locations[i] = new Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 + 100);
        }
        else
        {
            locations[i] = new Location(gameManager.getWidth() + rand() % 1001 + 200, gameManager.getHeight() / 2 - 100);
        }
    }
}

bool collidedWithCollider(Collider *c1, Collider *c2)
{
    int cx1 = c1->getLocation()->getX();
    int cx2 = c2->getLocation()->getX();
    int cy1 = c2->getLocation()->getY();
    int cy2 = c2->getLocation()->getY();
    int cr1 = c1->getSize();
    int cr2 = c2->getSize();

    return (sqrt(pow(cx2 - cx1, 2) + pow(cy2 - cy1, 2)) <= (cr1 + cr2)) ? true : false;
}

void handleOverLap()
{
    for (int i = 0; i < MAX_MOVING_OBJECTS; i++)
    {
        for (int j = 0; j < MAX_MOVING_OBJECTS; j++)
        {
            if (collidedWithCollider(colliders[i], colliders[j]))
            {
                // colliders[i]->move(getmaxwidth() + rand() % 300 + 100);
                colliders[i]->move(-10);
                // colliders[i]->moveBy(getmaxwidth() + rand() % 800 + 200, 0);
            }
        }
    }
}

void generateColliders()
{
    int count = 0;
    for (int i = 0; i < MAX_MOVING_OBJECTS; i++)
    {
        if (count < 2)
        {
            colliders[i] = new Coin(YELLOW, 30, locations[i]);
        }
        else if (count >= 2 && count < 4)
        {
            colliders[i] = new Obstacle(BLUE, 40, locations[i]);
        }
        else
        {
            colliders[i] = new EnemyVehicle(GREEN, 40, locations[i]);
        }

        count = count + 1;
    }
}

void relocateCollider(Collider *collider, int w)
{
    if (collider->getLocation()->getX() < 0)
    {
        collider->undraw();
        // random number between 200 and 900
        collider->moveTo(w + rand() % 701 + 200, collider->getLocation()->getY()); // 701 = 900 - 200 + 1
        collider->draw();
    }
}

int main()
{
    initMenu();
    game();

    return 0;
}
