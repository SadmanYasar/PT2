#include <iostream>
#include "Rectangle.hpp"
using namespace std;

/*
================================
COPY CONSTRUCTOR EXAMPLE
================================
*/
/* int main()
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
} */

/*
================================
OOP EXCEPTION EXAMPLE
================================
*/
void nLine()
{
    cout << "\n";
}

int main()
{
    int x, y;
    bool tryAgain = true;
    Rectangle myRectangle;

    cout << "Enter x and y: ";
    cin >> x >> y;
    nLine();

    while (tryAgain)
    {
        try
        {
            myRectangle.setX(x);
            myRectangle.setY(y);

            tryAgain = false;
        }
        catch (Rectangle::NegativeSize)
        {
            cout << "Negative value entered" << endl;
            cout << "Please enter non negative values: ";
            cin >> x >> y;
            nLine();
        }
    }

    cout << "Area: " << myRectangle.getArea() << endl;

    system("pause");
    return 0;
}