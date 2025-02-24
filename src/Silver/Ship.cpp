#include "Ship.hpp"
#include "Logger.hpp"
#include "Map.hpp"

namespace Silver
{

Ship::Ship(const std::shared_ptr<Map> & map)
    : _map{map}
    , _arrows{"🡡 ", "🡥 ", "🡢 ", "🡦 ", "🡣 ", "🡧 ", "🡠 ", "🡤 "}
    , _direction{0}
    , _x{10}
    , _y{10}
{
    _map->push(_x, _y);
}

Ship::~Ship()
{
    // _map->remove or pop(_x, _y);
}

void Ship::turnLeft()
{
    _direction = _direction == 0 ? NUM_DIRECTIONS - 1 : _direction - 1;

    _map->draw(_x, _y, _arrows[_direction]);
}

void Ship::turnRight()
{
    _direction = _direction == NUM_DIRECTIONS - 1 ? 0 : _direction + 1;

    _map->draw(_x, _y, _arrows[_direction]);
}

void Ship::move()
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
