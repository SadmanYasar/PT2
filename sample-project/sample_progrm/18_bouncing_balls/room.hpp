#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
	int x, y;		   // The center coordinates. For specifing the location of the ball
	int width, height; // For the dimension purposes
	int color;		   // For appearance purposes

public:
	Room(int _x = 0, int _y = 0, int _width = 0, int _height = 0, int _color = 0);

	int getX() const; // The left most x value of the room
	int getY() const; // The top most y value of the room
	int getWidth() const;
	int getHeight() const;
	int getColor() const;
	int getRight() const;  // The right most x value of the room
	int getBottom() const; // The bottom most y value of the room

	void setX(int value);
	void setY(int value);
	void setWidth(int value);
	void setHeight(int value);
	void setSize(int _width, int _height);
	void setColor(int value);
	void set(int _x, int _y, int _width, int _height, int _color);

	void draw() const;

	bool mouseClick(int mx, int my) const;
};

#endif
