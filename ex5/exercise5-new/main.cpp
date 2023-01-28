// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: Sadman Yasar Sayem    Location: Skudai, Johor (i.e. where are you currently located)
// Member 2's Name: Md Mostakim Reza   Location: Skudai, Johor

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  26/1/2023    9:48		   10:33          45

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

Shape *shapes[COUNT];
Shape *selectedShape = nullptr;

void drawShape(Shape *shape)
{
	shape->draw();
}

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
			int w = 50 + rand() % 300;
			int h = 50 + rand() % 300;

			shapes[i] = new Rect(x, y, w, h);
		}
	}
}

void processMouseClick()
{
	int mx, my;

	if (ismouseclick(WM_LBUTTONDOWN))
	{
		getmouseclick(WM_LBUTTONDOWN, mx, my);

		for (int i = 0; i < COUNT; i++)
		{
			if (shapes[i]->isMouseClicked(mx, my))
			{
				if (selectedShape)
				{
					selectedShape->toggleSelected();
				}

				selectedShape = (selectedShape == shapes[i]) ? nullptr : shapes[i];

				if (selectedShape)
				{
					selectedShape->toggleSelected();
				}
				break;
			}
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
				if (selectedShape)
					selectedShape->resize(1.2);
				break;

			case '-':
				if (selectedShape)
					selectedShape->resize(0.8);
				break;

			case KEY_LEFT:
				if (selectedShape)
					selectedShape->move(-10, 0);
				break;

			case KEY_RIGHT:
				if (selectedShape)
					selectedShape->move(10, 0);
				break;

			case KEY_UP:
				if (selectedShape)
					selectedShape->move(0, -10);
				break;

			case KEY_DOWN:
				if (selectedShape)
					selectedShape->move(0, 10);
				break;
			}
		}

		processMouseClick();
	}
	return 0;
}