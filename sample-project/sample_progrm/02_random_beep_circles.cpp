//  Program : An example of graphical program using WinBGIm graphic library and Beep sound
//
// ! Warning of Using this code:
//     You are allowed to re-use the code to your assignments and projects.
//     However it is limited only to code snippet.
//     Re-using the entire (or almost entire) of this code  is strictly prohibited.
//     Assignments and Projects that violate  this requirement will be disqualified .
//
//  WinBGIm documentation:
// ? https://www.cs.colorado.edu/~main/bgi/doc
//
// jumail@utm.my
// 17 Sep 2018

#include <graphics.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

int main( )
{
    int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width,height, "Graphic Application with BGI Library");

    srand(time(NULL));
    int sound = 500;
	while (!kbhit( ))
    {
		int color = COLOR(rand() % 256 , rand() % 256 , rand() % 256) ;
		int x = rand() % width;
		int y = rand() % height;
		int radius = rand() % 100 + 10;

		setcolor(color);
		circle(x,y,radius);
		sound = sound + 10;
		if (sound >1000) sound = 500;
		Beep(rand()%10 * 150, 50);
		delay(100);
    }
    getch();

    setcolor(COLOR(255,255,255));
	settextstyle(0, HORIZ_DIR, 18);
	outtextxy(10, 10, "Yey!!!.. Anda Menang!!!");
    getch();

    return 0;
}
