// (c) 2020. Jumail Bin Taliba, UTM Skudai Johor
// 8 Jan 2020
// Example on how to deal with include done twice, and how to centralized the includes

#include "include/system.hpp"

#include "include/object.hpp"
#include "include/circle.hpp"
#include "include/square.hpp"

int main()
{
	srand(time(NULL));

	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	const int SIZE = 5;

	Object *objects[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		int y = rand() % screenHeight; // intial y location is random, initial x fixed at 0
		int color = rand() % 15 + 1;
		int speed = rand() % 20 + 10;

		// randomly generate objects, whether it is a Circle or Square, decide randomly
		int r = rand() % 10; // generate random number between 0 to 9
		if (r < 5)
			objects[i] = new Circle(0, y, 50, color, speed);
		else
			objects[i] = new Square(0, y, 100, color, speed);
	}

	initwindow(screenWidth, screenHeight, "Shape");

	char ch = 0;

	for (int i = 0; i < SIZE; i++)
		objects[i]->draw();

	while (!kbhit()) // press any key to stop
	{
		delay(100);

		for (int i = 0; i < SIZE; i++)
			objects[i]->move();
	}

	getch();

	return 0;
}
