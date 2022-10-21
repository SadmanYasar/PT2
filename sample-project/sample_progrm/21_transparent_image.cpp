#include <graphics.h>
#include <string>
using namespace std;

typedef void *ImageMemory;

class Image
{
private:
	int left, top;
	int width, height;
	string imageFile;
	string maskFile;

	ImageMemory image;
	ImageMemory mask;
	ImageMemory background;

	int getMemorySize() const;
	ImageMemory loadImage(string file);
	void snapBackground();

public:
	Image(string _imageFile = "", string _maskFile = "", int _left = 0, int _top = 0, int _width = 0, int _height = 0);

	void read();
	void draw();
	void undraw();
	void move(int dx, int dy);

	int getLeft() const;
	int getTop() const;
	int getRight() const;
	int getBottom() const;
	void setPosition(int _left, int _top);

	int getWidth() const;
	int getHeight() const;
	void setDimension(int _width, int _height);
};

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Transparent Image - Press space to reverse");
	int movement = 50;

	Image image("resources/bear.jpg", "resources/bear_mask.jpg", 0, 0, 200, 220);
	image.setPosition(screenWidth / 2, screenHeight - image.getHeight() - 100);

	// create background with image
	readimagefile("resources/scroll_background3.jpg", 1, 1, screenWidth, screenHeight);

	image.read();

	char key = 0;

	while (key != 27)
	{
		key = 0;

		image.draw();
		delay(150);
		image.undraw();

		// auto reverse if reach the edge of the screen
		if ((image.getRight() >= screenWidth) ||
			(image.getLeft() <= 0))
			movement = -movement;

		image.move(movement, 0);

		if (kbhit())
		{
			key = getch();
			if (key == 0)
				key = getch();
		}

		switch (key)
		{
		case ' ':
			movement = -movement;
			break;

			// case KEY_LEFT:
			// 	image.undraw();
			// 	image.move(-10, 0);
			// 	image.draw();
			// 	break;

			// case KEY_RIGHT:
			// 	image.undraw();
			// 	image.move(10, 0);
			// 	image.draw();

			// 	break;
		}
	}

	return 0;
}

Image::Image(string _imageFile, string _maskFile, int _left, int _top, int _width, int _height)
{
	imageFile = _imageFile;
	maskFile = _maskFile;

	left = _left;
	top = _top;
	width = _width;
	height = _height;

	image = mask = background = nullptr;
}

void Image::read()
{
	if (image)
		delete[](char *) image;

	if (mask)
		delete[](char *) mask;

	image = loadImage(imageFile);
	mask = loadImage(maskFile);
}

int Image::getMemorySize() const { return imagesize(left, top, width, height); }

ImageMemory Image::loadImage(string file)
{
	ImageMemory image = new char[getMemorySize()];

	setactivepage(1);
	readimagefile(file.c_str(), left, top, getRight(), getBottom());
	getimage(left, top, getRight(), getBottom(), image);
	setactivepage(0);

	return image;
}

void Image::snapBackground()
{

	// If the background is first used, then allocate memory for it.
	//  Otherwise, reuse the allocated memory for the background

	if (!background)
		background = new char[getMemorySize()];

	getimage(left, top, getRight(), getBottom(), background);
}

void Image::draw()
{
	snapBackground();
	putimage(left, top, mask, OR_PUT);
	putimage(left, top, image, AND_PUT);
}

void Image::undraw()
{
	if (!background)
		return;
	putimage(left, top, background, COPY_PUT);
}

void Image::move(int dx, int dy)
{
	left += dx;
	top += dy;
}

int Image::getLeft() const { return left; }
int Image::getTop() const { return top; }
int Image::getRight() const { return left + width; }
int Image::getBottom() const { return top + height; }

void Image::setPosition(int _left, int _top)
{
	left = _left;
	top = _top;
}

int Image::getWidth() const { return width; }
int Image::getHeight() const { return height; }
void Image::setDimension(int _width, int _height)
{
	width = _width;
	height = _height;
}
