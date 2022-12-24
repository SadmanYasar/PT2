#ifndef POINT_H
#define POINT_H

class Point
{
private:
	int x, y;   
public:
	Point(int _x=0, int _y=0);

	int getX() const;
	int getY() const;
	void setX(int value);
	void setY(int value);
	void set(int _x, int _y);
	void move(int dx=0, int dy=0);
};

#endif
