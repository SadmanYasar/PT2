// #include <graphics.h>
// #include <iostream>
// using namespace std;

// class Ball
// {
// private:
//     // attributes or member variables
//     // location, size, presentation
//     int x, y;
//     int size;
//     int color;

// public:
//     // methods or member functions
//     // constructor, accesor (getter), mutator (setter), destructor

//     Ball(int _x, int _y, int _size, int _color = WHITE) : x(_x), y(_y), size(_size), color(_color) {}

//     int getX() const { return x; }

//     int left() const { return x - size; }
//     void left(int l) { x = l + size; }
//     int right() const { return x + size; }
//     void right(int r) { y = r + size; }

//     int getY() const { return y; }
//     void setY(int value) { y = value; }
//     int getColor() const { return color; }
//     void setColor(int value) { color = value; }

//     int getSize() const { return size; }
//     void setSize(int value) { size = value; }
//     // DRY vs WET code

//     void _draw(int c) const
//     {
//         setcolor(c);
//         setfillstyle(SOLID_FILL, c);
//         fillellipse(x, y, size, size);
//     }

//     void draw() const { _draw(color); }
//     void undraw() const { _draw(BLACK); }

//     void moveTo(int _x, int _y)
//     {
//         x = _x;
//         y = _y;
//     }

//     void moveBy(int dx, int dy)
//     {
//         x += dx;
//         y += dy;
//     }
// };

// int main()
// {
//     int screenWidth = getmaxwidth();
//     int screenHeight = getmaxheight();
//     char key = 0;

//     initwindow(screenWidth, screenHeight, "Simple Animation");

//     Ball b(200, screenHeight / 2, 100, COLOR(255, 0, 0));

//     b.draw();

//     Ball enemy(screenWidth - 100, screenHeight / 2, 100, COLOR(0, 255, 0));
//     enemy.draw();
//     while (key != 27) // 27 is the ASCII code for key Esc
//     {
//         enemy.moveBy(enemy.getX() - 10, 0);
//         if (kbhit())
//         {
//             key = getch();

//             if (key == 0) // special keys like arrow keys need to call to getch() twice.
//                 key = getch();

//             switch (key)
//             {
//             case 72:
//                 // up
//                 b.undraw();
//                 b.moveTo(b.getX(), screenHeight / 2 - 100);
//                 b.draw();
//                 break;
//             case 80:
//                 // down
//                 b.undraw();
//                 b.moveTo(b.getX(), screenHeight / 2 + 100);
//                 b.draw();
//                 break;
//             default:
//                 break;
//             }
//         }
//     }
//     return 0;
// }
