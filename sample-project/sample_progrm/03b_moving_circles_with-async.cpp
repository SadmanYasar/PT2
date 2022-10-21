#include <future>
using namespace std;

#include <graphics.h>

//--------------------------------------------------------------------------
class Circle
{
private:
	int x, y, r, c;
	int dx;

	void _draw(int color = 0) const
	{
		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		fillellipse(x, y, r, r);
	}

public:
	Circle(int _x = 0, int _y = 0, int _r = 0, int _c = WHITE, int _dx = 0) : x(_x), y(_y), r(_r), c(_c), dx(_dx) {}
	int left() const { return x - r; }
	int right() const { return x + r; }
	void reverse() { dx = -dx; }

	void move()
	{
		if ((right() >= getmaxx()) || (left() <= 0))
			reverse();
		undraw();

		x += dx;

		draw();
	}

	void draw() const { _draw(c); }
	void undraw() const { _draw(); }
};
//--------------------------------------------------------------------------

void animate(Circle *c)
{
	c->draw();

	while (!kbhit())
	{
		delay(100);
		c->move();

	} // while
}

int main()
{
	int w = getmaxwidth();
	int h = getmaxheight();

	initwindow(w, h, "Circle and async Examples");

	int x = w / 2;
	int size = 50;

	Circle a(x, h / 4, size, YELLOW, 50);
	Circle b(x, h / 2, size, RED, -30);

	// The followings is a normal Synchronous Programming (Blocking Programming)
	// The first call to function animate() blocks the program, preventing us to proceed to the second call
	// The second call to function animate() can only execute once the first call returns / terminates (i.e. by pressing any key)

	animate(&a);
	getch();
	animate(&b);

	// The followings is an example of an Asynchronous Programming (Non-Blocking Programming)
	// To test out this program, remove the comments below, and comment out the "sync code" above

	// future<void> f1(async(animate, &a));
	// future<void> f2(async(animate, &b));

	return 0;
}
