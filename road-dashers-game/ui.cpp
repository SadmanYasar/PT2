#include "include/ui.hpp"

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
