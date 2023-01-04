#include <string>

class Obstacle
{
private:
    string type;

public:
    Obstacle() {}

    Obstacle(string type) : type(type) {}

    string getType()
    {
        return type;
    }

    void setType(string t)
    {
        type = t;
    }
};