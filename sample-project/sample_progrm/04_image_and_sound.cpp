// Program : This program demonstrates how to
//            1). read an image file and display it onto the screen using the WinBGIm library
//            2). play a sound file
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
// readimagefile:
// ? https://www.cs.colorado.edu/~main/bgi/doc/readimagefile.html
//
// ?  Additional settings for VSCode:
//  To play sound, you need to add the linker parameter in your project with the following parameter.
//  open the file: .vscode/tasks.json
//  inside the label:  "winbgim_single_file", add the following line under the  "arrgs":
//    -lwinmm
//
// ?  Additional settings for DevC++:
//  To play sound, you need to add the linker parameter in your project with the following parameter.
//  goto Project->Project Options->Parameters->Linker   (and add the following parameter)
//    -lwinmm

// jumail@utm.my
// 19 March 2018

#include <graphics.h>

using namespace std;

int main()
{
	// Open a graphical window
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Program Example: Displaying Image.");

	string soundFile = "resources/jump_sound.wav";

	string imageFile = "resources/sphere_image.jpg";
	// image dimension: 262 x 263  (you can check it with paint, photo software)
	int imageWidth = 262;
	int imageHeight = 263;

	int x = width / 4.0;
	int y = 0;
	int dy = 50; // The number of steps of movement in y direction

	while (!kbhit())
	{

		readimagefile(imageFile.c_str(), x, y, x + imageWidth, y + imageHeight); // Load and display the image

		delay(100); // let the image stays on the screen for while before erasing it.

		// clear the image from the screen before moving to the next location
		//  for this purpose, we'll be drawing a black rectangle
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		bar(x, y, x + imageWidth, y + imageHeight);

		// Check whether the image already reach the top/bottom boundary. If so, change the direction of movement
		if ((y + imageHeight) >= height)
		{
			dy = -dy;
			y = height - imageHeight;

			PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC); // To play a sound file.
		}
		else if (y <= 0)
		{
			dy = -dy;
			y = 0;
			PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC);
		}

		// Move the image to a new location. Here, we move the image up and down direction
		y = y + dy;
	}

	return 0;
}
