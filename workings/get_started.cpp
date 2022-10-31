#include <iostream>
#include <graphics.h>
using namespace std;

/* class Employee
{

private:
    string Name;
    string Company;
    int Age;

public:
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void SayName()
    {
        cout << Name << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Sayem", "IAYH", 19);
    employee1.SayName();

    return 0;
} */

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    int x, y, radius, color;

    initwindow(screenWidth, screenHeight, "Hello world");

    x = screenWidth / 2;
    radius = 200;
    y = radius + 5;
    int speed = 20;
    circle(x, y, radius);

    while (1)
    {

        if (kbhit())
        {
            break;
        }

        y += speed;

        // draw the circle
        setcolor(WHITE);
        circle(x, y, radius);

        delay(100);
        // remove the circle
        setcolor(BLACK);
        circle(x, y, radius);

        if ((y + radius) >= screenHeight || (y - radius) <= 0)
        {
            speed = -speed;
        }
    }

    getch();
    return 0;
}