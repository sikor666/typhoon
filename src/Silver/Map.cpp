#include "Map.hpp"
#include "Ship.hpp"

#include "Bastet/Screen.hpp"

namespace Silver
{

Map::Map(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _width{_screen->getWidth() / 2}
    , _height{_screen->getHeight()}
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
