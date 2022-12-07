#include <iostream>
#include "Rectangle.hpp"
using namespace std;

/*
================================
COPY CONSTRUCTOR EXAMPLE
================================
*/
int main()
{
    Rectangle myRectangle;

    myRectangle.setY(5);
    cout << "Rect 1 Y: " << myRectangle.getY() << endl;

    cout << "After copying rect 1 onto 2:" << endl;

    Rectangle myRectangle2(myRectangle);

    cout << "Rect 1 Y: " << myRectangle.getY() << endl;
    cout << "Rect 2 Y: " << myRectangle2.getY() << endl;

    cout << "After changing rect 2 y:" << endl;
    myRectangle2.setY(10);

    cout << "Rect 1 Y: " << myRectangle.getY() << endl;
    cout << "Rect 2 Y: " << myRectangle2.getY() << endl;

    system("pause");
    return 0;
}