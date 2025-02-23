#include "Map.hpp"
#include "Bastet/Screen.hpp"

namespace Silver
{

Map::Map(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _width{_screen->getWidth() / 2}
    , _height{_screen->getHeight()}
{
    _water.resize(_height, std::vector<bool>(_width, false));
}

Map::~Map()
{
}

void Map::push(int x, int y)
{
    if (x < 0 or y < 0 or x >= _width or y >= _height)
        throw std::runtime_error{"Position is out of range"};

    if (_water[y][x])
        throw std::runtime_error{"Position is locked"};

    _water[y][x] = true;
}

} // namespace Silver
