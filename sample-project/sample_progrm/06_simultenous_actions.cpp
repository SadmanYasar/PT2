// Program : This program demonstrates how to perform "simultenous" actions for multiple objects.
// The trick to achieve simultenous movement is that use only a SINGLE LOOP for all objects.
// For discussion here, we use only movement as the action.
// The technique shown here can be extended for other actions such as
// user movements (e.g., user presses a key), animations, etc.
//
// ? Notes:
//    This program only applies collision detections with the balls and the left and right boundary of the screen.
//    No collision detections are done for balls to balls.
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
#include <ctime>

class Ball
{
  private:
	int x, y, r, c;
	int dx, dy;

	void display(int color) const
	{
		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		fillellipse(x, y, r, r);
	}

  public:
	Ball(int _x = 0, int _y = 0, int _r = 50, int _c = WHITE, int _dx = 0, int _dy = 0) : x(_x), y(_y), r(_r), c(_c)
	{
		setDirection(_dx, _dy);
	}

	void setDirection(int _dx = 0, int _dy = 0)
	{
		dx = _dx;
		dy = _dy;
	}
	void setPosition(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	void setColor(int _c)
	{
		c = _c;
	}

	void changeHorizontalDirection()
	{
		dx = -dx;

		PlaySound(TEXT("resources/jump_sound.wav"), NULL, SND_ASYNC); // Play a sound indicating the ball is bumping with the boundary
	}

	void changeVerticalDirection()
	{
		dy = -dy;

		PlaySound(TEXT("resources/jump_sound.wav"), NULL, SND_ASYNC);
	}

	void draw() const { display(c); }
	void undraw() const { display(BLACK); }

	void move(int dx, int dy)
	{
		undraw();
		x += dx;
		y += dy;
		draw();
		delay(50);
	}

	void move()
	{
		move(dx, dy);
	}

	// To check whether the ball has reached the vertical boundary (the left or right boundary of the screen)
	bool isOutOfVerticalBoundary()
	{
		int screenRight = getmaxwidth();
		int screenLeft = 0;
		int ballRight = x + r;
		int ballLeft = x - r;

		return (ballLeft < screenLeft) || (ballRight >= screenRight);
	}

	// To check whether the ball has reached the horizontal boundary (the top or bottom boundary of the screen)
	bool isOutOfHorizontalBoundary()
	{
		int screenBottom = getmaxheight();
		int screenTop = 0;
		int ballBottom = y + r;
		int ballTop = y - r;

		return (ballTop < screenTop) || (ballBottom >= screenBottom);
	}

	void doAction()
	{

		if (isOutOfVerticalBoundary())
			changeHorizontalDirection();

		if (isOutOfHorizontalBoundary())
			changeVerticalDirection();

		move();
	}
};

int main()
{
	/* initialize random seed: */
	// The reason using srand() here is to ensure that every time the program runs, the random is really random.
	//   If you don't put srand(), you will get the same random() every time your run the program

	srand(time(NULL));

	const int COUNT = 3;

	initwindow(getmaxwidth(), getmaxheight(), "Move");
	Ball balls[COUNT]; // Allocate memory for a list of balls

	// Set the attributes randomly for each ball.
	for (int i = 0; i < COUNT; i++)
	{
		int y = rand() % getmaxheight();
		int x = rand() % (getmaxwidth() - 50) + 50; // The term -50 and + 50 to ensure that the ball does not start at the lower or upper boundary of the screen. Otherwise, later the ball will be stucked there due to the testing in isOutOfLeft/RightBoundary()
		int c = COLOR(rand() % 256, rand() % 256, rand() % 256);

		int dx = rand() % 150 + 20; // this part only specify the magnitud of movement. You also need the direction. It will be done at the following line
		if (x > (getmaxwidth() / 2))
			dx = -dx; // if the initial location of the ball is at the right side, so it will be set to move to the left

		int dy = rand() % 150 + 20;
		if (y > (getmaxheight() / 2))
			dy = -dy;

		balls[i].setDirection(dx, dy);
		balls[i].setPosition(x, y);
		balls[i].setColor(c);
	}

	for (int i = 0; i < COUNT; i++)
		balls[i].draw();

	/* The following loop is the key part of this program to achieve simultenous movement */
	while (!kbhit())
	{

		for (int i = 0; i < COUNT; i++) // The use of the loop for is that just to simplify the code. Otherwise, you need to write for each object, eg.. balls[0].doAction(); balls[1].doAction(); and so on
			balls[i].doAction();
	}

	return 0;
}
