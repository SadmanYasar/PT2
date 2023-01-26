#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
	int x, y;	   // for location
	bool selected; // to indicate whether the shape is selected or not

public:
	Shape(int _x = 0, int _y = 0);
	void setLocation(int _x, int _y);
	void setSelected(bool _selected);

	void move(int dx, int dy);
	virtual void draw() const = 0;
	virtual void undraw() const = 0;
	virtual void resize(double scale) = 0;
	virtual bool isMouseClicked(int mx, int my) const = 0;
};

#endif