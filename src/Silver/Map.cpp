#include "Map.hpp"
#include "Bastet/Screen.hpp"

#include <curses.h>

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
    if (not valid(x, y))
        throw std::runtime_error{"Position is out of range"};

    if (_water[y][x])
        throw std::runtime_error{"Position is locked"};

    _water[y][x] = true;
}

void Map::draw(int x, int y)
{
    if (not _water[y][x])
        throw std::runtime_error{"Position is empty"};

    _screen->draw(x, y, COLOR_PAIR(5), "  ");
    _screen->refresh();
}

void Map::move(int x, int y, int a, int b)
{
    if (not valid(x, y))
        throw std::runtime_error{"Position is out of range"};

    if (not valid(a, b))
        throw std::runtime_error{"Position is out of range"};

    if (not _water[y][x])
        throw std::runtime_error{"Position is empty"};

    if (_water[b][a])
        throw std::runtime_error{"Position is locked"};

    _water[y][x] = false;
    _water[b][a] = true;

    _screen->draw(x, y, COLOR_PAIR(6), "  ");
}

bool Map::valid(int x, int y)
{
    return x >= 0 and y >= 0 and x < _width and y < _height;
}

} // namespace Silver
