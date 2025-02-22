#include "Ship.hpp"

namespace Silver
{

Ship::Ship()
    : direction{0}
    , x{0}
    , y{0}
{
}

Ship::~Ship()
{
}

void Ship::setPosition(int posx, int posy)
{
    x = posx;
    y = posy;
}

int Ship::getDirection() const
{
    return direction;
}

int Ship::getX() const
{
    return x;
}

int Ship::getY() const
{
    return y;
}

} // namespace Silver
