#include "include/ui.hpp"
#include "include/location.hpp"
#include <string>

UI::UI(string text, int color, int value, Location *location)
{
    this->text = text;
    this->color = color;
    this->value = value;
    this->location = location;
}

int UI::getColor() const
{
    return color;
}

void UI::setColor(int c)
{
    color = c;
}

string UI::getText() const
{
    return text;
}

void UI::setText(string t)
{
    text = t;
}

int UI::getValue() const
{
    return value;
}

void UI::setValue(int v)
{
    value = v;
}

void UI::display() const
{
    setcolor(color);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
    bgiout << text;
    outstreamxy(location->getX(), location->getY());
    if (value)
    {
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);
        bgiout << value;
        outstreamxy(location->getX(), location->getY() - 20);
    }
}

Location *UI::getLocation()
{
    return location;
}

void UI::setLocation(Location &_location)
{
    *location = _location;
}
