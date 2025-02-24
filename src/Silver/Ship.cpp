#include "Ship.hpp"
#include "Logger.hpp"
#include "Map.hpp"

namespace Silver
{

Ship::Ship(const std::shared_ptr<Map> & map)
    : _map{map}
    , _arrows{"🡡 ", "🡥 ", "🡢 ", "🡦 ", "🡣 ", "🡧 ", "🡠 ", "🡤 "}
    , _direction{0}
    , _position{10.0f, 10.0f}
{
    _map->push(_position, _arrows[_direction]);
}

Ship::~Ship()
{
    // _map->remove or pop(_position);
}

void Ship::turnLeft()
{
    _direction = _direction == 0 ? NUM_DIRECTIONS - 1 : _direction - 1;

    _map->draw(_position, _arrows[_direction]);
}

void Ship::turnRight()
{
    _direction = _direction == NUM_DIRECTIONS - 1 ? 0 : _direction + 1;

    _map->draw(_position, _arrows[_direction]);
}

void Ship::move()
{
    _position = _map->move(_position, _direction, _arrows[_direction]);
}

int Ship::getDirection() const
{
    return _direction;
}

Vector2 Ship::getPosition() const
{
    return _position;
}

} // namespace Silver
