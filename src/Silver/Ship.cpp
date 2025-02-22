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
