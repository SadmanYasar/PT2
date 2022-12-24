// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Tutorial 7: Associations, Aggregation and Composition

#include <graphics.h>
#include "ball.hpp"
#include "room.hpp"

// Task 5:
//    Review the main function before running.

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();

	initwindow(screenWidth, screenHeight, "Tutorial 7-Associations");

	Room r1(0,0,screenWidth, screenHeight, 0);
	Ball b1( Point(100, screenHeight/4), 100, YELLOW, 50, 0);   // move horizontally

	r1.draw();
	b1.draw();

	while (!kbhit())
	{
		delay(125);
		b1.move();
	}

	return 0;
}
