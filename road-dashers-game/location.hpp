#ifndef LOCATION_H
#define LOCATION_H

class Location
{
private:
    int x;
    int y;

public:
    Location(int x = 0, int y = 0);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void setLocation(int x, int y);
};

#endif
