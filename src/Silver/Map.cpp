#include "Map.hpp"
#include "Bastet/Screen.hpp"

// FIXME: define colors
#include <curses.h>

namespace Silver
{

Map::Map(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _width{_screen->getWidth()}
    , _height{_screen->getHeight()}
{
    _water.resize(_width, std::vector<bool>(_height, false));
}

Map::~Map()
{
}

void Map::push(int x, int y, const std::string & s)
{
    if (not valid(x, y))
        throw std::runtime_error{"Position is out of range"};

    if (_water[x][y])
        throw std::runtime_error{"Position is locked"};

    _water[x][y] = true;

    _screen->draw(x, y, COLOR_PAIR(5), s);
}

void Map::draw(int x, int y, const std::string & s)
{
    if (not valid(x, y))
        throw std::runtime_error{"Position is out of range"};

    if (not _water[x][y])
        throw std::runtime_error{"Position is empty"};

    _screen->draw(x, y, COLOR_PAIR(5), s);
}

void Map::move(int & x, int & y, int direction, const std::string & s)
{
    if (not valid(x, y))
        throw std::runtime_error{"Position is out of range"};

    if (not _water[x][y])
        throw std::runtime_error{"Position is empty"};

    int a;
    int b;

    switch (direction)
    {
        case 0: a = x + 0; b = y - 1; break;
        case 1: a = x + 1; b = y - 1; break;
        case 2: a = x + 1; b = y - 0; break;
        case 3: a = x + 1; b = y + 1; break;
        case 4: a = x + 0; b = y + 1; break;
        case 5: a = x - 1; b = y + 1; break;
        case 6: a = x - 1; b = y + 0; break;
        case 7: a = x - 1; b = y - 1; break;

        default: throw std::runtime_error{"Direction is wrong"};
    }

    if (not valid(a, b))
        throw std::runtime_error{"Position is out of range"};

    if (_water[a][b])
        throw std::runtime_error{"Position is locked"};

    _water[x][y] = false;
    _water[a][b] = true;

    _screen->draw(x, y, COLOR_PAIR(6), "  ");
    _screen->draw(a, b, COLOR_PAIR(5), s);

    x = a;
    y = b;
}

bool Map::valid(int x, int y)
{
    return x >= 0 and y >= 0 and x < _width and y < _height;
}

} // namespace Silver
