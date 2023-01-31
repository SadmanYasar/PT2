#include <graphics.h>
#include "include/coin.hpp"
#include "include/collider.hpp"
#include "include/player.hpp"
#include "include/ui.hpp"
#include "include/game.hpp"

Coin::Coin(int _color, int _size, Location *_location, int _value) : Collider(_color, _size, _location), value(_value) {}

int Coin::getValue() const
{
    return value;
}

void Coin::setValue(int v)
{
    value = v;
}

void Coin::handleCollision(Player &player, UI &score, Game &gameManager)
{
    if (hasHitPlayer(player))
    {
        PlaySound(TEXT("assets/sounds/collectcoin.wav"), NULL, SND_ASYNC);
        undraw();
        moveTo(gameManager.getWidth() + rand() % 701 + 200, player.getLocation()->getY());
        score.setValue(score.getValue() + 1);
    }
}
