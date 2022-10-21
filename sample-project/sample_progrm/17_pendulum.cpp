#include <graphics.h>
#include <cmath>

class Pendulum
{
private:
	int x, y;	 // Position of anchor
	int length;   // string length
	int size;	 // ball radius
	double angle; // to specify the position of the ball
	double delta; // delta angle, the movement
	int color;

	void _draw(int _color) const;
	int ballX() const;
	int ballY() const;

public:
	Pendulum(int _x = 0, int _y = 0, int _length = 0, int _size = 0, double _angle = 0, double _delta = 0, int _color = 0);

	void draw() const;
	void undraw() const;
	void move();
};

#define PI 3.1415

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Pendulums");

	Pendulum p(screenWidth * 0.2, screenHeight / 2, 300, 50, PI / 12, PI / 12, WHITE);
	Pendulum q(screenWidth * 0.5, screenHeight / 2, 300, 50, PI / 12, PI / 9, YELLOW);
	Pendulum r(screenWidth * 0.8, screenHeight / 2, 300, 50, PI / 12, PI / 16, GREEN);

	while (!kbhit())
	{
		p.draw();
		q.draw();
		r.draw();

		delay(150);

		p.undraw();
		q.undraw();
		r.undraw();

		p.move();
		q.move();
		r.move();
	}

	return 0;
}

Pendulum::Pendulum(int _x, int _y, int _length, int _size, double _angle, double _delta, int _color)
	: x(_x), y(_y), length(_length), size(_size), angle(_angle), delta(_delta), color(_color)
{
}

void Pendulum::_draw(int _color) const
{
	int bx = ballX();
	int by = ballY();

	setcolor(_color);
	setfillstyle(SOLID_FILL, _color);

	// draw the string
	line(x, y, bx, by);

	// draw the ball
	fillellipse(bx, by, size, size);
}

int Pendulum::ballX() const { return x + length * cos(angle); }

int Pendulum::ballY() const { return y + length * sin(angle); }

void Pendulum::draw() const { _draw(color); }
void Pendulum::undraw() const { _draw(0); }
void Pendulum::move()
{
	const double MAXRIGHT = 8 * PI / 9;
	const double MAXLEFT = PI / 9;
	angle += delta;

	if ((angle > MAXRIGHT) || (angle < MAXLEFT))
		delta = -delta;
}
