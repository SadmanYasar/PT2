// Program : This program demonstrates how to display objects using polygons
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
#include<cmath>

using namespace std;

struct Point{
	int x, y;
};

class Poly{   // It seems we can't use "Polygon" here. Same issue as "Rectangle"
	private:
		int capacity;   // The maximum number of points
		int count;      // The actual number of points
		Point *points;  // The list of points

		int colorOutline;
		int colorFill;

	public:
		// Constructor
		Poly(int _capacity=0, int _colorOutline= WHITE, int _colorFill=BLACK)
		{	count = 0;
			points = NULL;
		    setCapacity(_capacity);
			colorOutline=_colorOutline; colorFill=_colorFill;
		}

		// Destructor
		~Poly()
		{ if (points) delete[] points;}

		// Mutators
		void setCapacity(int c) {
			if (c==0) return; // do not accept zero capacity

			if (points) delete[] points;  // since we want to recreate the array, we need to delete the existing list first
			capacity=c;
			count = 0;  // Since the list is new, we need to start over. i.e., no point at all

			points = new Point[capacity];  // Allocate memory for the array/list
		}

		void addPoint(int x, int y)
		{
			if (count>=capacity) return;  // Can't add more point if the list is already full

			points[count].x = x;
			points[count].y = y;
			count++;
		}

		void setOutlineColor(int _colorOutline){ colorOutline=_colorOutline;}
		void setFillColor(int _colorFill){ colorFill=_colorFill;}
		void setColor(int _colorOutline, int _colorFill){ colorOutline=_colorOutline, colorFill = _colorFill;}


		void move(int dx=0, int dy=0)   // move the all the points in horizontal direction(dx) and vertical direction (dy)
		{
			for (int i=0; i<count; i++){
				points[i].x += dx;
				points[i].y += dy;
			}
		}

		// Accessors
		int getCapacity() const { return capacity;}
		int getCount() const { return count;}

		int getOutlineColor() const { return colorOutline;}
		int getFillColor() const { return colorFill;}

		int getMaxX() const {
			int maxx = points[0].x;
			for (int i=1; i<count; i++)
				if (points[i].x>maxx) maxx = points[i].x;

			return maxx;
		}

		int getMinX() const {
			int minx = points[0].x;
			for (int i=1; i<count; i++)
				if (points[i].x<minx) minx = points[i].x;

			return minx;
		}

		void draw() const
		{
			setcolor(colorOutline);
			setfillstyle(SOLID_FILL, colorFill);
			fillpoly(count, (int*)points);
		}

		void erase(int color=0) const  // assuming the background is black
		{
			setcolor(color);
			setfillstyle(SOLID_FILL, color);
			fillpoly(count, (int*)points);
		}


};

#define PI 3.14159265

int main( )
{

	int w = getmaxwidth();
    int h = getmaxheight();


	initwindow(w, h, "Polygon Examples");

	Poly triangle(3,WHITE, RED);   // To create a triangle from the class Polygon
	triangle.addPoint( 100,100 );
	triangle.addPoint( 400,300 );
	triangle.addPoint( 50,300 );

	Poly rect(5, YELLOW, GREEN);    // To create a rectangle from the class Polygon
	rect.addPoint(50,350);
	rect.addPoint(250,350);
	rect.addPoint(250,550);
	rect.addPoint(50,550);

	int numberOfSlices = 5; // pentagon
	double radius = 140;
	Point center={200,800};

	Poly pentagon(numberOfSlices,WHITE, COLOR(127,127,127));   // To create a pentagon from the class Polygon
	double radPerSlice = 2*PI/ numberOfSlices;
	for (int i=1; i<=numberOfSlices; i++)
		pentagon.addPoint(center.x + radius*cos(i*radPerSlice), center.y + radius*sin(i*radPerSlice) );

	int inc1 = 30;  // increment for the triangle
	int inc2 = 50;  // increment for the rectangle
	int inc3 = 20;  // increment for the circle

	while (!kbhit()){
		triangle.draw();
		rect.draw();
		pentagon.draw();

		delay (80);

		triangle.erase();
		rect.erase();
		pentagon.erase();

		if ( (triangle.getMaxX()>=w) || (triangle.getMinX()<=0) ) inc1 = -inc1;  // Change the direction of movement when the object reaches the border
		if ( (rect.getMaxX()>=w) || (rect.getMinX()<=0) ) inc2 = -inc2;  // Change the direction of movement when the object reaches the border
		if ( (pentagon.getMaxX()>=w) || (pentagon.getMinX()<=0) ) inc3 = -inc3;  // Change the direction of movement when the object reaches the border

		triangle.move(inc1);  // Only move in horizontal direction
		rect.move(inc2);
		pentagon.move(inc3);
	}

    return 0;
}
