// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Tutorial 7: Associations, Aggregation and Composition

#include <graphics.h>
#include <ctime>

#include "ball.hpp"
#include "room.hpp"

int main()
{
	srand(time(NULL));

	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	int roomWidth = screenWidth / 2 - 100;

	initwindow(screenWidth, screenHeight, "Bouncing balls - Click the mouse on any room");

	Room r1(0, 0, roomWidth, screenHeight, BLUE);
	Room r2(roomWidth + 200, 0, roomWidth, screenHeight, RED);

	Ball b1(100, 500, 100, GREEN, 25, 25);
	Ball b2(100, 100, 100, YELLOW, -25, 50);
	Ball b3(screenWidth / 2 + 200, 100, 100, WHITE, 50, 50);

	Room *rooms[5] = {&r1, &r2};
	int nRooms = 2;

	Ball *balls[50] = {&b1, &b2, &b3};
	int nBalls = 3;

	int mx, my;

	for (int i = 0; i < 2; i++)
		balls[i]->setRoom(rooms[0]);

	for (int i = 2; i < nBalls; i++)
		balls[i]->setRoom(rooms[1]);

	for (int i = 0; i < nRooms; i++)
		rooms[i]->draw();

	for (int i = 0; i < nBalls; i++)
		balls[i]->draw();

	while (!kbhit())
	{
		delay(125);

		for (int i = 0; i < nBalls; i++)
			balls[i]->move();

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, mx, my);

			// find the room
			int roomIndex = -1;

			for (int i = 0; i < nRooms; i++)
			{
				if (rooms[i]->mouseClick(mx, my))
				{
					roomIndex = i;
					break;
				}
			}

			if (roomIndex != -1)
			{
				balls[nBalls] = new Ball(100, 500, 100, GREEN, 25, 2);
				balls[nBalls]->setRoom(rooms[roomIndex]);
				balls[nBalls]->setRandom();
				balls[nBalls]->setLocation(Point(mx, my));
				nBalls++;
			}
		}
	}

	return 0;
}
