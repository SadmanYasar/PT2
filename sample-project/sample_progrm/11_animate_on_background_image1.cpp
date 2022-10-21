// Program : This program demonstrates how to animate drawing on top of a background image
//
// ? Normally, animation effect is done by these three simple steps: undraw(), move( to new location), and draw()
// ? And to undraw(), it is simply drawing the object with the background color (e.g. BLACK)
//
// However, when the background is an image, the color is not simply a single color (e.g. only BLACK).
//  Thus, you cannot simply clear the object by drawing the background color because no spesific single background color.
//
// ? The tricks or key idea to solve this issue is that:
// ?  using the XOR drawing mode.
//
//  Truth table of xor operations:
//     0 xor 0 = 0   <===
//     0 xor 1 = 1
//     1 xor 0 = 1
//     1 xor 1 = 0   <===
//
//  Simply put: the result will 0 if both operands are the same.
//
//  What does this mean to our problem:
//  It means that, when you draw an object on top of the same object, it will clear the object
//
// ! Warning of Using this code:
//     You are allowed to re-use the code to your assignments and projects.
//     However it is limited only to code snippet.
//     Re-using the entire (or almost entire) of this code is strictly prohibited.
//     Assignments and Projects that violate  this requirement will be disqualified .
//
// jumail@utm.my
// 19 April 2018
//
#include <graphics.h>
#include<string>
using namespace std;

class Ball{
	private:
		int x, y, r, c;
		int dx, dy;

	public:
		Ball(int _x=0, int _y=0, int _r=50, int _c=WHITE):x(_x), y(_y), r(_r), c(_c)
		{}

		void setPosition(int _x, int _y){
			x = _x; y=_y;
		}

		void setColor(int _c){
			c = _c;
		}

		void draw() const {
			setcolor(c);
			//setlinestyle(SOLID_LINE,0,2);  // The third parameter is the line's thickness
			//circle(x,y,r);

		  	// You can also experiment with filled circles
			setfillstyle(SOLID_FILL, c);
		  	fillellipse(x,y,r,r);
		}

		void move(int dx=0, int dy=0){
			x +=dx;
			y +=dy;
		}


};

int main( )
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow( screenWidth, screenHeight, "Moving an object on top of a background image");

	// Load the background image file and display it onto the window
	string imageFile = "resources/background.jpg";

	// Load the image from the file and scale it to full screen
	readimagefile(imageFile.c_str(), 0, 0, screenWidth, screenHeight);

	// Create a Ball object and position it at the middle left of the screen
	Ball ball (0,screenHeight/2, 100, DARKGRAY );

	setwritemode(XOR_PUT);

	ball.draw();  // First call to draw() will put the ball onto the window
	getch();

	ball.draw();  // Second call to draw() will erase the ball from the window as we use the XOR write/display mode
	getch();

	// Do a simple animation
	while (!kbhit()){
		ball.draw();  // first time drawing to draw();
		delay(100);
		ball.draw();  // second time drawing to clear
		ball.move(10,0);
	}

	getch();

	return 0;
}



