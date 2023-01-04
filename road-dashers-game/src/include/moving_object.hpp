#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

class movingObject
{
private:
    string color;
    int speed;

public:
    Location loc;
    int getColor() const;
    void setColor(string c);
    int getSpeed() const;
    void setSpeed(int s);
    void move();
};

#endif
