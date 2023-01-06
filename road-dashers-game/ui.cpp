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

void UI::display()
{
    setcolor(12);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
    bgiout << "POINTS";
    outstreamxy(getmaxwidth() * 0.91, getmaxheight() * 0.1);
    // outstreamxy(screenWidth * 0.91, screenHeight * 0.1);
    // Points Counter
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);
    bgiout << "00";
    outstreamxy(getmaxwidth() * 0.93, getmaxheight() * 0.05);
}