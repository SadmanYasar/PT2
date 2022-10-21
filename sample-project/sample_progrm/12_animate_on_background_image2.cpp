//
// Program : This program demonstrates how to animate drawing on top of a background image
//
// Normally, animation effect is done by these three simple steps: undraw(), move( to new location), and draw()
// And to undraw(), it is simply drawing the object with the background color (e.g. BLACK)
//
// However, when the background is an image, the color is not simply a single color (e.g. only BLACK).
//  Thus, you cannot simply clear the object by drawing with the background color because no spesific single background color.
//
// In previous program, we were using an XOR mode. However, with this method, the effect is not quite satisfactory.
//  Especially, you won't get the actual color that you set for the object.
//
//? Now, we are going to use another strategy, i.e.,:
//  Before start drawing the object, we need to "snap" or "capture" the background,
//  and store the snap image into a buffer held by the object.
//  Then, to clear the object from the scene, simply put back the snap image.
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
		void* snapBackground;  // This is the buffer to hold the snap background (underneath the object)

	public:
		Ball(int _x=0, int _y=0, int _r=50, int _c=WHITE):x(_x), y(_y), r(_r), c(_c)
		{
			// allocate memory for the image to read
			int imageLength = 2*r;   // image width and height are the same as it a circle
			int size = imagesize(0, 0, imageLength, imageLength);  // memory size in bytes

			snapBackground = new char[size];  // This is only to allocate memory. No background is snap yet.
		}

		~Ball()
		{
			// This an example, when to use a destructor
			// Because the memory for snapBackground is allocated dynamically (in the constructor)
			// you need to destroy the memory literaly... here in the destructor

			delete [] snapBackground;  // using a bracket because snapBackground is allocated as an array (see construtor)
		}


		void draw() const {
			// Before doing any drawing, we need to capture or snap the background image at
			//  the location we want to put the ball.
			getimage(x-r,y-r,x+r,y+r, snapBackground);

			// Now, we are good to go ..... to start drawing
			setcolor(c);
			setfillstyle(SOLID_FILL, c);
		  	fillellipse(x,y,r,r);
		}

		void undraw() const {
			// To clear the object, we simply put back the snap background onto the screen

			putimage(x-r,y-r,snapBackground,COPY_PUT);
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
	Ball ball (0,screenHeight/2, 80, COLOR(255,140,0) );

	while (!kbhit()){
		ball.draw();
		delay(100);
		ball.undraw();
		ball.move(10,0);
	}

	getch();

	return 0;
}



