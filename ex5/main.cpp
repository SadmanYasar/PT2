// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: Sadman Yasar Sayem    Location: KLG (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
//   _________

#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "shape.hpp"
#include "circle.hpp"
#include "rect.hpp"

using namespace std;

// ? Notes: Choose the debug mode "Multi-File Graphic Project" to run this program.

// You may change the max size of the list
#define COUNT 5

void drawShape(Shape *shape)
{
	shape->draw();
}

Shape *shapes[COUNT];
void generateListOfShapes(int width, int height)
{
	for (int i = 0; i < COUNT; i++)
	{
		int side = rand() % 2;
		int x = 1 + rand() % width;
		int y = 1 + rand() % height;

		if (side == 0)
		{
			int radius = 50 + rand() % 300;
			shapes[i] = new Circle(x, y, radius);
		}
		else
		{
			int width = 50 + rand() % 300;
			int height = 50 + rand() % 300;

			shapes[i] = new Rect(x, y, width, height);
		}
	}
}

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Exercise 5");

	/* initialize random seed: */
	srand(time(NULL));
	generateListOfShapes(width, height);

	for (int i = 0; i < COUNT; i++)
	{
		shapes[i]->draw();
	}

	char ch = 0;

	while (ch != 27) // 27 is ESC key
	{
		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{
			case '+':
				break;

			case '-':
				break;

			case KEY_LEFT:
				break;

			case KEY_RIGHT:
				break;

			case KEY_UP:
				break;

			case KEY_DOWN:
				break;
			}
		}

		if (ismouseclick(WM_LBUTTONDOWN))
		{
		}
	}
	return 0;
}