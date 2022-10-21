#include <graphics.h>
#include <string>
using namespace std;

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Scrolling background -  Press the LEFT or RIGHT arrow key");

	void *background;
	int imageWidth = screenWidth;
	int imageHeight = screenHeight;
	int size = imagesize(0, 0, imageWidth, imageHeight);
	background = new char[size];

	// Load the image from the file and scale it to full screen
	string imageFile = "resources/scroll_background3.jpg";

	readimagefile(imageFile.c_str(), 0, 0, screenWidth, screenHeight);
	getimage(0, 0, imageWidth - 1, imageHeight - 1, background);

	int left1 = 0;
	int left2 = left1 + imageWidth;
	int speed = 150;
	char ch = 0;

	while (ch != 27)
	{
		putimage(left1, 0, background, COPY_PUT);
		putimage(left2, 0, background, COPY_PUT);

		if (kbhit())
		{
			ch = getch();
			if (ch == 0)
			{
				ch = getch();
				if (ch == 75)
				{ // left
					left1 += speed;
					left2 += speed;

					int right1 = left1 + imageWidth;
					int right2 = left2 + imageWidth;

					if ((right1 >= screenWidth) && (right2 >= screenWidth))
					{
						if (right2 > right1)
							left2 = left1 - imageWidth;
						else
							left1 = left2 - imageWidth;
					}
				}
				else if (ch == 77)
				{
					// right
					left1 -= speed;
					left2 -= speed;

					if ((left1 <= 0) && (left2 <= 0))
					{
						if (left1 < left2)
							left1 = left2 + imageWidth;
						else
							left2 = left1 + imageWidth;
					}
				}
			}
		}
	}

	return 0;
}
