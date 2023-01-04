#include <string>

class UI
{
private:
    string text;
    string color;

public:
    UI(string text, string color) : text(text), color(color) {}

    string getColor()
    {
        return color;
    }

    void setColor(string c)
    {
        color = c;
    }

    string getText()
    {
        return text;
    }

    void setText(string t)
    {
        text = t;
    }
};
