#include <string>
#include <graphics.h>
using namespace std;

#pragma once

class UI
{
private:
      string text;
      int color;

public:
      UI(string text = "", int color = COLOR(255, 0, 0)) : text(text), color(color) {}

      int getColor() const;

      void setColor(int c);

      string getText() const;

      void setText(string t);

      void display();
};
