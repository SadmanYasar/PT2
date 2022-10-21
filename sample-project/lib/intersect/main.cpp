// Notes: Run the program with "Multi-File Console program" mode
// Uncomment the following lines of code that you want to test out

#include<iostream>
#include "intersect.hpp"
using namespace std;

void print(string prompt, bool result) { cout << prompt << " result: " << result << endl; }
int main()
{
	bool c;
	//testing rectangular collision detection

	c = intersectRect(0,0,10,10,20,10,10,10);
	//c = intersectRect(0,0,10,10,5,5,10,10);
	//c = intersectRect(0,0,10,10,0,5,10,10);
	//c = intersectRect(0,0,10,10,0,15,10,10);
	//c = intersectRect(0,0,10,10,5,5,2,2);
	print("Testing rectangular collision detection", c);

	//testing circular collision detection
	c = intersectCircle(10,10,10,10,10,100);
	//c = intersectCircle(10,10,10,100,10,100);
	//c = intersectCircle(10,10,10,100,10,10);
	//c = intersectCircle(10,10,10,10,25,4);
	//c = intersectCircle(10,10,10,10,25,5);
	print("Testing circular collision detection", c);

	//testing elliptical collision detection
	c = intersectEllipse(10,10,10,10,10,10,100,100);
	//c = intersectEllipse(10,10,10,10,100,10,100,100);
	//c = intersectEllipse(10,10,10,10,100,10,10,100);
	print("Testing elliptical collision detection", c);


	//testing collision detection between rectangle and circles
	c = intersectRectCircle(0,0,10,20,5,10,5);
	//c = intersectRectCircle(0,0,10,20,20,10,5);
	//c = intersectRectCircle(0,0,10,20,15,10,5);
	print("Testing collision detection between rectangle and circles", c);
	
	system("pause");
	
	return 0;
	
}
