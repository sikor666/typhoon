#include "Ship.hpp"

namespace Silver
{

Ship::Ship()
    : _direction{0}
    , _x{0}
    , _y{0}
{
}

Ship::~Ship()
{
}

void Ship::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

int Ship::getDirection() const
{
    return _direction;
}

int Ship::getX() const
{
    return _x;
}

int Ship::getY() const
{
    return _y;
}

} // namespace Silver
