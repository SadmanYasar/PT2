#include <graphics.h>
#include "space_ship.hpp"

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Space Shooter");

	SpaceShip s1(screenWidth/2, screenHeight-100);
	char ch;

	s1.draw();

	while (true)
	{
		delay(40);
		s1.doAction();

		if (kbhit())
		{
			ch = getch();

			if (ch == 27)
				break;
			else if (ch == ' ')
				s1.shoot();
			else if (ch == 0)
			{
				ch = getch();

				switch (ch)
				{
				case 75:
					s1.move(-10);
					break;

				case 77:
					s1.move(10);
					break;
				}
			}
		}
	}

	return 0;
}
