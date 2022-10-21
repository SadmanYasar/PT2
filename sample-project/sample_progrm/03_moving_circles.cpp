// Program : This program demonstrates how to perform a simple animation, i.e., moving circles
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
// 17 Sep 2018

#include <graphics.h>
using namespace std;

class Circle
{
  private:
	int x, y, r;
	int colorOutline;
	int colorFill;

  public:
	// Constructor
	Circle(int _x = 0, int _y = 0, int _r = 0, int _colorOutline = COLOR(255, 255, 255), int _colorFill = 0)
	{
		x = _x;
		y = _y;
		r = _r;
		colorOutline = _colorOutline;
		colorFill = _colorFill;
	}

	// Mutators
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setCenter(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void setR(int _r) { r = _r; }
	void setOutlineColor(int _colorOutline) { colorOutline = _colorOutline; }
	void setFillColor(int _colorFill) { colorFill = _colorFill; }
	void setColor(int _colorOutline, int _colorFill) { colorOutline = _colorOutline, colorFill = _colorFill; }

	// Accessors
	int getX() const { return x; }
	int getY() const { return y; }
	int getR() const { return r; }
	int getOutlineColor() const { return colorOutline; }
	int getFillColor() const { return colorFill; }
	int getMaxX() const { return x + r; }
	int getMinX() const { return x - r; }
	int getMaxY() const { return y + r; }
	int getMinY() const { return y - r; }

	void draw() const
	{
		setcolor(colorOutline);
		setfillstyle(SOLID_FILL, colorFill);
		fillellipse(x, y, r, r);
	}
};

int main()
{
	string banner = "Welcome to the world of computer programming .....";
	int w = getmaxwidth();
	int h = getmaxheight();

	initwindow(w, h, "Circle Examples");
	setfillstyle(SOLID_FILL, BLUE);
	bar(0, 0, w, h); // fill the background with BLUE

	Circle a(w / 2, h / 2, h / 20);
	Circle b(h / 2, h / 2, h / 20);

	a.setFillColor(YELLOW);
	b.setFillColor(RED);

	setwritemode(XOR_PUT); // To set the graphical display mode such that, when you draw an object on the same object, the effect will be, the object will be cleared

	int inc1 = 30; // increment for Circle a
	int inc2 = 20; // increment for Circle b

	while (!kbhit())
	{
		a.draw(); // First drawing, will display the circle
		b.draw();

		delay(80);

		a.draw(); // Second drawing, will clear the circle as we draw the same thing. This is the effect of the XOR_PUT drawing mode
		b.draw();

		if ((a.getMaxX() >= w) || (a.getMinX() <= 0))
			inc1 = -inc1; // Change the direction of movement when the circle reaches the border
		if ((b.getMaxX() >= w) || (b.getMinX() <= 0))
			inc2 = -inc2; // Change the direction of movement when the circle reaches the border

		a.setX(a.getX() + inc1);
		b.setX(b.getX() + inc2);
	}

	return 0;
}
