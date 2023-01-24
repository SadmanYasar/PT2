// ? EXERCISE 5: POLYMORPHISM

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
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

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Exercise 5");

	/* initialize random seed: */
	srand(time(NULL));

	char ch = 0;

	while (ch != 27)  // 27 is ESC key
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