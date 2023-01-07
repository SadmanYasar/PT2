#include <string>
#include <graphics.h>
#include "location.hpp"
using namespace std;

#pragma once

class UI
{
private:
      int value;
      string text;
      int color;
      Location *location;

public:
      UI(string text = "", int color = COLOR(255, 255, 0), int value = 0, Location *location = nullptr)
      {
            this->text = text;
            this->color = color;
            this->value = value;
            this->location = location;
      }

      int getColor() const;

      void setColor(int c);

      string getText() const;

      void setText(string t);

      int getValue() const;

      void setValue(int v);

      void display() const;

      Location *getLocation();
      void setLocation(Location &_location);
};
