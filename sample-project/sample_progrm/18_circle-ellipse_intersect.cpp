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
// 18 Dec 2019

#include <graphics.h>
#include <cmath>

#define PI 3.1415

// Converting degree to radian and vise-versa
double radian(double d) { return d / 180.0 * PI; }
double degree(double r) { return r / PI * 180.0; }

class AnEllipse
{
private:
	int x, y, rx, ry;
	int bgcolor;

public:
	AnEllipse(int _x = 0, int _y = 0, int _rx = 0, int _ry = 0, int _color = BLUE)
	{
		x = _x;
		y = _y;
		rx = _rx;
		ry = _ry;
		bgcolor = _color;
	}

	int getRadiusX() const { return rx; }
	int getRadiusY() const { return ry; }
	int getCenterX() const { return x; }
	int getCenterY() const { return y; }

	int getColor() const
	{
		return bgcolor;
	}

	// the x coordinate for the edge at d degree
	int getEdgeX(double d) const
	{
		double theta = radian(d);
		return x + rx * cos(theta);
	}

	int getEdgeY(double d) const
	{
		double theta = radian(d);
		return y + ry * sin(theta);
	}

	void draw() const
	{
		setcolor(bgcolor);
		setfillstyle(SOLID_FILL, bgcolor);
		fillellipse(x, y, rx, ry);
	}
};

class Circle
{
private:
	int x, y, r, dx, dy;
	int color;
	AnEllipse *room;

public:
	Circle(int _x = 0, int _y = 0, int _r = 0, int _color = WHITE, AnEllipse *_room = NULL)
	{
		x = _x;
		y = _y;
		r = _r;
		color = _color;
		dx = dy = 0;
		room = _room;
	}

	int getRadius() const { return r; }
	int getCenterX() const { return x; }
	int getCenterY() const { return y; }

	// the x coordinate for the edge at d degree
	int getEdgeX(double d) const
	{
		double theta = radian(d);
		return x + r * cos(theta);
	}

	int getEdgeY(double d) const
	{
		double theta = radian(d);
		return y + r * sin(theta);
	}

	// To calculate the degree of this circle toward point (x,y). The point can be the mouse location
	int getDegreeToPoint(int mx, int my)
	{
		double dx = mx - x;
		double dy = my - y;
		double theta = atan2(dy, dx);
		return degree(theta);
	}

	void setMovementAtDegree(double d)
	{
		double theta = radian(d);
		double speed = 0.20 * r; //each movement is 20% from the radius
		dx = speed * cos(theta);
		dy = speed * sin(theta);
	}

	double getDirectionDegree() const
	{
		double theta = atan2(dy, dx);
		return degree(theta);
	}

	void move()
	{
		double d = getDirectionDegree();
		int ex = getEdgeX(d);
		int ey = getEdgeY(d);
		int distX = abs(ex - room->getCenterX());
		int distY = abs(ey - room->getCenterY());

		// allow movement only if the ball does not touch the room's edge

		if ((distX >= room->getRadiusX()) || (distY > room->getRadiusY()))
			return;

		undraw();
		x += dx;
		y += dy;
		draw();
	}
	void draw() const
	{
		setcolor(color);
		circle(x, y, r);
	}

	void undraw() const
	{
		int bgcolor = room->getColor();
		setcolor(bgcolor);
		circle(x, y, r);
	}
};

int main()
{
	int w = getmaxwidth();
	int h = getmaxheight();

	initwindow(w, h, "Circle-AnEllipse intersection Example");

	AnEllipse room(w / 2, h / 2, w / 4, w / 8);
	Circle ball(w / 2, h / 2, w / 16, YELLOW, &room);
	room.draw();

	setcolor(WHITE);
	for (int d = 0; d <= 90; d += 45)
		line(room.getCenterX(), room.getCenterY(), room.getEdgeX(d), room.getEdgeY(d));
	getch();

	int mx, my;
	double lookAtMouseDegree;

	while (!kbhit())
	{
		delay(100);
		ball.move();

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			lookAtMouseDegree = ball.getDegreeToPoint(mx, my);
			ball.setMovementAtDegree(lookAtMouseDegree);
		}
	}

	return 0;
}
