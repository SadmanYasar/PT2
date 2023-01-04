#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle extends movingObject
{
private:
    string name;

public:
    Coin *coin;
    Vehicle();
    string getName() const;
    void setName(string n);
    ~Vehicle();
    myVehicle.earn(myCoin);
    myVehicle.hit(myObstacle);
};

#endif
