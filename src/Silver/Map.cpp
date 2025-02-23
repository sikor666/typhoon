#include "Map.hpp"
#include "Ship.hpp"

namespace Silver
{

Map::Map(int width, int height)
    : _width{width}
    , _height{height}
{
}

Map::~Map()
{
}

bool Map::push(const std::shared_ptr<Ship> & ship)
{
    int x = ship->getX();
    int y = ship->getY();

    if (x < 0 or y < 0 or x >= _width or y >= _height)
        return false;

    if (_water[y][x])
        return false;

    _water[y][x] = ship;

    return true;
}

} // namespace Silver
