// Program : This program demonstrates how to display moving images using buffering technique.
//           In the previous program (image_and_sound) the image is quite flickery.
//           The reason was that, the image was read from the the external file every time you call to function readimage()
//
//           ? The solution to reduce flickering effect:
//               * only read from the external file once
//               * store the read image in a buffer (use function getimage for this)
//               * display the image many times using image from the buffer (use function putimage for this)
//
//
// ! Warning of Using this code:
//     You are allowed to re-use the code to your assignments and projects.
//     However it is limited only to code snippet.
//     Re-using the entire (or almost entire) this code  is strictly prohibited.
//     Assignments and Projects that violate  this requirement will be disqualified .
//
//  WinBGIm documentation:
// ? https://www.cs.colorado.edu/~main/bgi/doc
//
// readimagefile, getimage, putimage:
// ? https://www.cs.colorado.edu/~main/bgi/doc/readimagefile.html
// ? https://www.cs.colorado.edu/~main/bgi/doc/getimage.html
// ? https://www.cs.colorado.edu/~main/bgi/doc/putimage.html
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
//
// jumail@utm.my
// 20 March 2018

#include <graphics.h>
using namespace std;

int main()
{
	// Open a graphical window
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Bouncing balls");

	string imageFile = "resources/sphere_image.jpg";
	string soundFile = "resources/jump_sound.wav";

	// image dimension: 262 x 263  (you can check it with paint, photo software)
	int imageWidth = 262;
	int imageHeight = 263;

	int x1 = width / 4.0;
	int y1 = 0;
	int dy1 = 50; // The number of steps of movement in y direction

	int x2 = width / 2.0;
	int y2 = imageHeight;
	int dy2 = -25; // The number of steps of movement in y direction

	// allocate memory for the image to read
	int size = imagesize(0, 0, imageWidth, imageHeight); // memory size in bytes
	void *image = new char[size];

	// read image from the external file and put it anywhere on the screen
	//   to prepare for the getimage(), as getimage() must get image from the screen

	readimagefile(imageFile.c_str(), 0, 0, imageWidth, imageHeight);

	// Copy the image from the screen into the buffer.
	getimage(0, 0, imageWidth, imageHeight, image);

	// Once the image has been copied, clear it from the screen
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, imageWidth, imageHeight);

	while (!kbhit())
	{
		// display the image at the location you want
		putimage(x1, y1, image, COPY_PUT);
		putimage(x2, y2, image, COPY_PUT);

		delay(100); // let the image stays on the screen for while before clearing it.

		// clear the image from the screen before moving to the next location
		//  for this purpose, we'll be drawing a black rectangle
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		bar(x1, y1, x1 + imageWidth, y1 + imageHeight);
		bar(x2, y2, x2 + imageWidth, y2 + imageHeight);

		// Check whether the image already reach the top/bottom boundary. If so, change the direction of movement
		if ((y1 + imageHeight) >= height)
		{
			dy1 = -dy1;
			y1 = height - imageHeight;

			PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC); // To play a sound file.
		}
		else if (y1 <= 0)
		{
			dy1 = -dy1;
			y1 = 0;
			PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC);
		}

		if ((y2 + imageHeight) >= height)
		{
			dy2 = -dy2;
			y2 = height - imageHeight;

			PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC); // To play a sound file.
		}
		else if (y2 <= 0)
		{
			dy2 = -dy2;
			y2 = 0;
			PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC);
		}

		// Move the image to a new location. Here, we move the image up and down direction
		y1 += dy1;
		y2 += dy2;
	}

	// free up the memory when the image is no more used.
	delete[] image;

	return 0;
}
