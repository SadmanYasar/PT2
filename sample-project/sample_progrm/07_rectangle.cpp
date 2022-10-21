// Program : This program demonstrates how to display rectangles,
//           and perform a simple collision detection with the window borders
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

#include <graphics.h>
using namespace std;

class Rect
{ // It seems the identifier 'Rectangle' has been used by other library. Thus, use a different name hre
  private:
	int x, y, w, h;
	int colorOutline;
	int colorFill;

  public:
	// Constructor
	Rect(int _x = 0, int _y = 0, int _w = 0, int _h = 0, int _colorOutline = WHITE, int _colorFill = BLACK)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		colorOutline = _colorOutline;
		colorFill = _colorFill;
	}

	// Mutators
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setTopLeft(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	void setW(int _w) { w = _w; }
	void setH(int _h) { h = _h; }
	void setDimension(int _w, int _h)
	{
		w = _w;
		h = _h;
	}

	void setOutlineColor(int _colorOutline) { colorOutline = _colorOutline; }
	void setFillColor(int _colorFill) { colorFill = _colorFill; }
	void setColor(int _colorOutline, int _colorFill) { colorOutline = _colorOutline, colorFill = _colorFill; }

	// Accessors
	int getX() const { return x; }
	int getY() const { return y; }
	int getW() const { return w; }
	int getH() const { return h; }

	int getOutlineColor() const { return colorOutline; }
	int getFillColor() const { return colorFill; }
	int getMaxX() const { return x + w; }
	int getMaxY() const { return y + h; }

	void draw() const
	{
		setcolor(colorOutline);
		setfillstyle(SOLID_FILL, colorFill);
		bar(x, y, x + w, y + h);
	}

	void erase(int color = 0) const // assuming the background is black
	{
		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		bar(x, y, x + w, y + h);
	}
};

int main()
{
	int w = getmaxwidth();
	int h = getmaxheight();

	initwindow(w, h, "Rectangle Examples");

	Rect r(200, 200, 150, 80);
	r.setColor(COLOR(255, 0, 0), COLOR(0, 255, 0));

	int inc = 30;

	while (!kbhit())
	{
		r.draw();
		delay(80);
		r.erase();

		if ((r.getMaxX() >= w) || (r.getX() <= 0))
			inc = -inc; // Change the direction of movement when the object reaches the border

		r.setX(r.getX() + inc);
	}

	return 0;
}
