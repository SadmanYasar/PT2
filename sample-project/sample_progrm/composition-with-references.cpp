#include <iostream>
using namespace std;

class Shape
{
public:
	virtual int area() const = 0;
};

class Circle : public Shape
{
	int r;

public:
	Circle(int _r = 0) : r(_r) {}
	int area() const { return 3.14 * r * r; }
};

class Rectangle : public Shape
{
	int w, h;

public:
	Rectangle(int _w = 0, int _h = 0) : w(_w), h(_h) {}
	int area() const { return w * h; }
};

int main()
{
	Circle c(10);
	Rectangle r(3, 4);
	Rectangle r2(1, 2);
	// Shape *s = &c;

	// // cout << c.area() << endl;
	// // cout << r.area() << endl;
	// // cout << s->area() << endl;
	// // s = &r;
	// // cout << s->area() << endl;

	// Shape &ref = r2;
	// cout << ref.area() << endl;

	// ref = r;
	// cout << ref.area() << endl;

	int list[3] = {-1, 332, 3};

	for (int i : list)
		cout << i << endl;

	system("pause");
}