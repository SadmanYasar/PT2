
// Program : This program demonstrates how to display a graphical objects onto the screen
//           using the WinBGIm graphic library
//
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
//
// jumail@utm.my
// 17 Sep 2018

#include <graphics.h>
#include <cstdlib>
#include <ctime>

int main()
{

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    int x, y, radius, color;

    initwindow(screenWidth, screenHeight, "An example of graphical program using WinBGIm library");

    srand(time(NULL));
    while (!kbhit())
    {
        x = rand() % screenWidth;
        y = rand() % screenHeight;
        radius = rand() % ((screenHeight / 4) + 50);
        color = COLOR(rand() % 255, rand() % 255, rand() % 255);

        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse(x, y, radius, radius);

        delay(100);
    }

    getch();

    return 0;
}
