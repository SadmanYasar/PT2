
#include <graphics.h>

class Ball
{
private:
    // attributes or member variables
    // location, size, presentation
    int x, y;
    int size;
    int color;

public:
    // methods or member functions
    // constructor, accesor (getter), mutator (setter), destructor

    Ball(int _x, int _y, int _size, int _color = WHITE) : x(_x), y(_y), size(_size), color(_color) {}

    int getX() const { return x; }

    int left() const { return x - size; }
    void left(int l) { x = l + size; }
    int right() const { return x + size; }

    int getY() const { return y; }
    void setY(int value) { y = value; }
    void setColor(int value) { color = value; }

    void _draw(int c) const
    {
        setcolor(c);
        setfillstyle(SOLID_FILL, c);
        fillellipse(x, y, size, size);
    }

    void draw() const { _draw(color); }
    void undraw() const { _draw(BLACK); }

    void moveTo(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    void moveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Simple Animation");

    Ball balls[5] = {
        Ball(screenWidth / 2, screenHeight / 2, 100, COLOR(255, 0, 0)),
        Ball(screenWidth / 4, screenHeight / 2, 100, COLOR(255, 100, 0)),
        Ball(screenWidth / 8, screenHeight / 2, 100, COLOR(255, 0, 100)),
        Ball(screenWidth / 2, screenHeight / 4, 100, COLOR(188, 0, 0)),
        Ball(screenWidth / 3, screenHeight / 2, 100, COLOR(255, 255, 0)),
    };

    for (int i = 0; i < 5; i++)
    {
        balls[i].draw();
    }
    getch();

    for (int i = 0; i < 5; i++)
    {
        balls[i].undraw();
        balls[i].moveBy(0, 100);
        balls[i].draw();
    }
    getch();
    getch();

    return 0;
}