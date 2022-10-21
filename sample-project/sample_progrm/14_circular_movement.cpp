
// Program :
//
//
// ! Warning of Using this code:
//     You are allowed to re-use the code to your assignments and projects.
//     However it is limited only to code snippet.
//     Re-using the entire (or almost entire) of this code  is strictly prohibited.
//     Assignments and Projects that violate  this requirement will be disqualified .
//
//  WinBGIm documentation:
// ? https://www.cs.colorado.edu/~main/bgi/doc
//
//
// jumail@utm.my
// 27 Nov 2018

#include <graphics.h>
#include <cmath>

class Point
{
  private:
    int x, y;

  public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    void rotate(double theta, Point pivot)
    {
        double x1 =  x;
        double y1 =  y;
        double px = pivot.getX();
        double py = pivot.getY();


        y1 = -y1;
        py = -py;

        x1 = x1 - px;
        y1 = y1 - py;

        double _x = x1;
        double _y = y1;

        double cosine = cos(theta);
        double sinus = sin(theta);

        x1 = _x * cosine - _y * sinus;
        y1 = _x * sinus + _y * cosine;

        x1 = x1 + px;
        y1 = y1 + py;

        y1 = -y1;

        x =  x1;
        y =  y1;
    }
};

class Line
{
  private:
    Point s, e;

    void drawHelper(int c) const
    {
        setcolor(c);
        line(s.getX(), s.getY(), e.getX(), e.getY());
    }

  public:
    Line(Point _s, Point _e) : s(_s), e(_e) {}
    void draw() const { drawHelper(YELLOW);}
    void undraw() const { drawHelper(RED);}
    void rotate(double theta)
    {
        undraw();
        e.rotate(theta, s);
        draw();
    }
};

#define PI 3.1416

int main()
{

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Circular movement ");

    // Line line(Point(screenWidth/2, screenHeight/2), Point(screenWidth/2, screenHeight/2-400) );
    Line line(Point(0,0), Point(100,0) );
    line.draw();

    double rotateDegree = 90*PI/180;

    while (!kbhit())
    {
        delay(100);
        line.rotate(rotateDegree);
    }

    getch();

    return 0;
}
