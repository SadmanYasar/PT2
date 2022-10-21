// This code shows the following:
//  -1). implemeting polymorphism
//  -2). implemeting collision
//
// Author: Jumail Bin Taliba, UTM
// Email : jumail@utm.my
// Date  : 11 Feb 2021

// Notes:
// Use the code only for reference. 

// To run this program: use "Graphic Program" debug mode

#include <graphics.h>
#include <cmath>

// Class Point is a convinient class
class Point
{
private:
	int x, y;

public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	int getX() const { return x; }
	int getY() const { return y; }
	void set(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void shift(int dx = 0, int dy = 0)
	{
		x += dx;
		y += dy;
	}

	// distance between another point
	double operator-(const Point &p) const
	{
		double dx = x - p.x;
		double dy = x - p.y;
		return sqrt(dx * dx + dy * dy);
	}
};

class Shape
{
protected:
	int color;
	int dx, dy;
	virtual void _draw(int _color) const = 0; // this method will only be called by draw() and undraw(). It is to achieve more DRY code, i.e., reduce code duplication
	
	// These two methods are helper to determine which part of the ball collide with the shapes
	//  They will be used to decide whether to reverse movement horizotally or vertically.

	bool horizIntersect(int x) { return (left() <= x) && (x <= right()); }
	bool vertIntersect(int y) { return (top() <= y) && (y <= bottom()); }

public:
	Shape(int _color = WHITE, int _dx = 0, int _dy = 0) : color(_color), dx(_dx), dy(_dy) {}
	int getColor() const { return color; }
	void setColor(int _color) { color = _color; }
	void setMovement(int _dx, int _dy)
	{
		dx = _dx;
		dy = _dy;
	}
	void reverseHorizontal() { dx = -dx; }
	void reverseVertical() { dy = -dy; }

	virtual void draw() const { _draw(color); }
	virtual void undraw() const { _draw(BLACK); }
	virtual void shift() = 0;
	void move()
	{
		undraw();
		shift();
		draw();
	}

	// To get the position and size, e.g. left() and width() should be
	//  polymorphic because, circles and rectangles store their information differently.
	//  Therefore they need to have their own versions for the methods. Thus polyrmophic methods.

	virtual int width() const = 0;
	virtual int height() const = 0;
	virtual Point center() const = 0;
	virtual int left() const = 0;
	virtual int top() const = 0;
	virtual int right() const { return left() + width(); }
	virtual int bottom() const { return top() + height(); }

	// Testing whether a shape collide to another no need to be polymorphic
	//  because the way the collision is done is always the same, i.e.,
	//  by testing overlapping between rectangular information

	bool collision(Shape *with) const
	{
		int dx = abs(center().getX() - with->center().getX());
		int dy = abs(center().getY() - with->center().getY());
		int sum_rx = width() / 2 + with->width() / 2;
		int sum_ry = height() / 2 + height() / 2;

		return ((dx <= sum_rx) && (dy <= sum_ry));
	}

	// This mehtod is not necessarily to be polymorphic (as for this example program).
	// However, in your application you may want to make this method polymorphic.
	
	// What the method does is that, reverse the movement of the ball. But it depends
	//  on which side the ball collide with.
	
	virtual void onCollision(Shape *with)
	{
		if (with->horizIntersect(left()) || with->horizIntersect(right()))
			with->reverseHorizontal();

		if (with->vertIntersect(top()) || (with->vertIntersect(bottom())))
			with->reverseVertical();
	}
};

class Rect : public Shape
{
protected:
	Point topLeft, size;

	void _draw(int _color) const
	{
		setfillstyle(SOLID_FILL, _color);
		setcolor(_color);
		bar(left(), top(), right(), bottom());
	}

public:
	Rect(Point _topLeft, Point _size, int _color) : Shape(_color), topLeft(_topLeft), size(_size) {}
	int width() const { return size.getX(); }
	int height() const { return size.getY(); }
	Point center() const { return Point(left() + width() / 2, top() + height() / 2); }
	int left() const { return topLeft.getX(); }
	int top() const { return topLeft.getY(); }
	void shift() { topLeft.shift(dx, dy); }
};

class Circle : public Shape
{
protected:
	Point c; // center
	int radius;

	void _draw(int _color) const
	{
		setfillstyle(SOLID_FILL, _color);
		setcolor(_color);
		fillellipse(c.getX(), c.getY(), radius, radius);
	}

public:
	Circle(Point _c, int _radius, int _color) : Shape(_color), c(_c), radius(_radius) {}

	int width() const { return radius*2; }
	int height() const { return radius*2; }
	Point center() const { return c; }
	int left() const { return c.getX() - radius; }
	int top() const { return c.getY() - radius; }
	void shift() { c.shift(dx, dy); }
};

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();

	initwindow(screenWidth, screenHeight, "Collision Demo");

	// Create the objects (as well as setting up their information) before manipulating them
	// These objects will involve in polymorphism
	Shape *objects[] = {
		
		// The first four objects are for the screen boundaries
		new Rect(Point(0, 0), Point(screenWidth, 50), GREEN), 
		new Rect(Point(0, screenHeight - 50), Point(screenWidth, 50), GREEN),
		new Rect(Point(0, 50), Point(50, screenHeight - 100), YELLOW),
		new Rect(Point(screenWidth - 50, 50), Point(50, screenHeight - 100), YELLOW),

		// The remaining objects are in the middle of the screen
		new Circle(Point(200, 200), 100, RED),
		new Rect(Point(300, 600), Point(400, 100), GREEN),
		new Circle(Point(1000, 150), 50, BLUE),
		new Rect(Point(1500, 500), Point(50, 300), CYAN),
	};

	int count = 8;

	// Draw the walls and objects
	for (int i = 0; i < count; i++)
		objects[i]->draw();

	// Create a ball. Only this object will move.
	Circle ball(Point(screenWidth / 2, screenHeight - 200), 50, WHITE);
	ball.setMovement(10, -50);
	ball.draw();

	int ch = 0;
	Shape *collidedObject = NULL;

	while (ch != 27) // stop once ESC is pressed
	{
		if (kbhit()){
			ch = getch();
			if (ch==' ') ball.reverseVertical(); // Just for fun. The ball reverses the movement if SPACE is pressed
		}

		// Find an object that the ball is colliding with.
		
		collidedObject = NULL;
		for (int i = 0; i < count; i++)
		{
			if (objects[i]->collision(&ball))
			{
				collidedObject = objects[i];  // keep track which object is currently being hit by the ball, because later on we want to use for redraw and other manipulation
				break;  // once an object found, stop the loop. Because at one time the ball can hit only one object.
			}
		}

		delay(100);

		if (collidedObject != NULL)
		{
			// If there is an object colliding with the ball, let the object decide what to do (onCollision)
			//  and also, we need redraw the object.
			collidedObject->onCollision(&ball);
			ball.move();
			collidedObject->draw();
		}
		else
			ball.move();  // If no collision, then just move the ball
	}

	getch();
	return 0;
}
