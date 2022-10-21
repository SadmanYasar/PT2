
#include <graphics.h>
#include <string>
using namespace std;

#include "image.hpp"

Image::Image(int _width, int _height)
{
    width = _width;
    height = _height;
    image = mask = background = nullptr;
}

Image::~Image() { free(); }

void Image::free()
{
    if (image)
        delete[](ImageData) image;
    if (mask)
        delete[](ImageData) mask;
    if (background)
        delete[](ImageData) background;
}

void Image::read(string imageFile, string maskFile)
{
    image = loadImage(imageFile);
    mask = loadImage(maskFile);
}

int Image::getMemorySize() const { return imagesize(0, 0, width, height); }

ImageData Image::loadImage(string file)
{
    ImageData _image = new char[getMemorySize()];

    setactivepage(1);
    readimagefile(file.c_str(), 0, 0, width, height);
    getimage(0, 0, width, height, _image);
    setactivepage(0);

    return _image;
}

void Image::snapBackground(int left, int top)
{

    // If the background is first used, then allocate memory for it.
    //  Otherwise, reuse the allocated memory for the background

    if (!background)
        background = new char[getMemorySize()];

    getimage(left, top, left + width, top + height, background);
}

void Image::draw(int left, int top)
{
    snapBackground(left, top);
    putimage(left, top, mask, OR_PUT);

    putimage(left, top, image, AND_PUT);
}

void Image::undraw(int left, int top)
{
    if (!background)
        return;
    putimage(left, top, background, COPY_PUT);
}

int Image::getWidth() const { return width; }
int Image::getHeight() const { return height; }
void Image::setWidth(int value) { width = value; }
void Image::setHeight(int value) { height = value; }
