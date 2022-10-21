// Program : This program demonstrates how to perform collision detection and simultenous actions
//
// ! Warning of Using this code:
//     You are allowed to re-use the code to your assignments and projects.
//     However it is limited only to code snippet.
//     Re-using the entire (or almost entire) of this code is strictly prohibited.
//     Assignments and Projects that violate  this requirement will be disqualified .
//
//  WinBGIm documentation:
// ? https://www.cs.colorado.edu/~main/bgi/doc
//
// jumail@utm.my
// 28 March 2018

#include<cmath>
#include<ctime>
#include <graphics.h>

using namespace std;

int distance(int x1, int y1, int x2, int y2)
{
	return sqrt( pow(x1-x2, 2) + pow(y1-y2,2) );
}

bool isColliding(int x1, int y1, int x2, int y2, int r1, int r2 )
{
	double d = distance(x1, y1, x2, y2);
	return ( d <(r1+r2) );
}

int main( )
{
    string banner = "Welcome to the world of computer programming .....";
	int w = getmaxwidth();
    int h = getmaxheight();

	initwindow(w, h, "First Sample");

    srand(time(NULL));

    int r1 = 50 + rand() % 50;
    int r2 = 50 + rand() % 50;

	int x1 = rand() % (w-r1);
    int y1 = rand() % (h-r1);
    int inc1 = 50;

    int x2 = rand() % (w-r2);
    int y2 = rand() % (h-r2);
    int inc2 = 50;

    while (!kbhit()){

		// diplay banner text
		settextstyle(BOLD_FONT, HORIZ_DIR, 10);
		setcolor(YELLOW);
		outtextxy(0,0, (char*)banner.c_str());


		// draw circle1
		setfillstyle(SOLID_FILL, YELLOW);
		setcolor(YELLOW);
		fillellipse(x1,y1,r1,r1);

		// draw circle2
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(WHITE);
		fillellipse(x2,y2,r2,r2);

		// Allow all the graphic elements shown on the screen for a while, before clearing them
		delay(80);



		// test for collision between the two circles
		bool c = isColliding(x1,y1, x2, y2, r1, r2);

		// Clear the all the objects by drawing them with the same color as the background
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(BLACK);

		// clear the circle 1
		fillellipse(x1,y1,r1,r1);

		// clear the circle 2
		fillellipse(x2,y2,r2,r2);


		// clear the banner text
		settextstyle(BOLD_FONT, HORIZ_DIR, 10);
		setcolor(YELLOW);
		outtextxy(0,0, (char*)banner.c_str());


		// Update the movement, for next drawing
		if ( ( (y1+r1) >= h) || ((y1-r1)<=0) || c ) {
			inc1 = -inc1;
			Beep(100, 50);
		}
		y1 += inc1;


		if ( ( (x2+r2) >= w) || ((x2-r2)<=0) || c ) {
			inc2 = -inc2;
			Beep(100, 50);
		}
		x2 += inc2;

		// update the banner text, i.e., first character will be put at the end
		banner += banner.substr(0,1); // append the first character to the end
		banner.erase(0,1); // then erase it

    }


    return 0;
}
