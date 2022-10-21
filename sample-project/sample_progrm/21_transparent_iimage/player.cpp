#include <graphics.h>

#include "player.hpp"
#include "image.hpp"

Player::Player(int _left, int _top, int _width, int _height)
    : left(_left), top(_top),
      width(_width), height(_height),
      movement(0),
      image(_width, _height) {}

void Player::init() { 
    image.read("images/bear.jpg", "images/bear_mask.jpg"); 
}

void Player::draw() { image.draw(left, top); }

void Player::undraw() { image.undraw(left,top);}

void Player::move() { left += movement; }

void Player::reverse() { movement = -movement; }

int Player::getLeft() const { return left; }

void Player::setLeft(int value) { left = value; }

void Player::setTop(int value) { top = value; }

int Player::getRight() const { return left + width; }

int Player::getTop() const { return top; }

int Player::getBottom() const { return top + height; }

int Player::getHeight() const { return height; }

int Player::getMovement() const { return movement; }
void Player::setMovement(int value) { movement = value; }
