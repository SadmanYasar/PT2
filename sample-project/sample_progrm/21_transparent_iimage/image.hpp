#pragma once

#include<string>
using namespace std;

typedef char *ImageData;

class Image
{
private:
    int width, height;

    ImageData image, mask, background;

    int getMemorySize() const;
    ImageData loadImage(string file);
    void snapBackground(int left, int top);

public:
    Image(int _width=0, int _height=0);
    ~Image();
    void read(string imageFile, string maskFile);
    void free();
    void draw(int left, int top);
    void undraw(int left, int top);

    int getWidth() const;
    int getHeight() const;
    void setWidth(int value);
    void setHeight(int value);
};