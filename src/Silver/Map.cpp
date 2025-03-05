#include "Map.hpp"
#include "Bastet/Screen.hpp"
#include "Logger.hpp"

namespace Silver {

Map::Map(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _width{_screen->getDisplay(0)->width()}
    , _height{_screen->getDisplay(0)->height()}
{
    _water.resize(_width, std::vector<bool>(_height, false));
}

Map::~Map()
{
}

void Map::push(const Vector2 & pos, const std::string & str)
{
    if (not valid(pos.x, pos.y))
        throw std::runtime_error{"Position is out of range"};

    if (_water[pos.x][pos.y])
        throw std::runtime_error{"Position is locked"};

    _water[pos.x][pos.y] = true;

    _screen->getDisplay(0)->print(pos, Bastet::Color::WhiteMagenta, str);
}

void Map::pop(const Vector2 & pos)
{
    if (not valid(pos.x, pos.y))
        throw std::runtime_error{"Position is out of range"};

    if (not _water[pos.x][pos.y])
        throw std::runtime_error{"Position is empty"};

    _water[pos.x][pos.y] = false;

    _screen->getDisplay(0)->print(pos, Bastet::Color::WhiteBlue, "  ");
}

void Map::update(const Vector2 & pos, const std::string & str)
{
    if (not valid(pos.x, pos.y))
        throw std::runtime_error{"Position is out of range"};

    if (not _water[pos.x][pos.y])
        throw std::runtime_error{"Position is empty"};

    _screen->getDisplay(0)->print(pos, Bastet::Color::WhiteMagenta, str);
}

Vector2 Map::move(const Vector2 & pos, int direction, const std::string & str)
{
    if (not valid(pos.x, pos.y))
        throw std::runtime_error{"Position is out of range"};

    if (not _water[pos.x][pos.y])
        throw std::runtime_error{"Position is empty"};

    Vector2 res;

    switch (direction)
    {
        case 0: res = pos + Vector2{+0, -1}; break;
        case 1: res = pos + Vector2{+1, -1}; break;
        case 2: res = pos + Vector2{+1, -0}; break;
        case 3: res = pos + Vector2{+1, +1}; break;
        case 4: res = pos + Vector2{+0, +1}; break;
        case 5: res = pos + Vector2{-1, +1}; break;
        case 6: res = pos + Vector2{-1, +0}; break;
        case 7: res = pos + Vector2{-1, -1}; break;

        default: throw std::runtime_error{"Direction is wrong"};
    }

    if (not valid(res.x, res.y))
        throw std::runtime_error{"Position is out of range"};

    if (_water[res.x][res.y])
        throw std::runtime_error{"Position is locked"};

    _water[pos.x][pos.y] = false;
    _water[res.x][res.y] = true;

    _screen->getDisplay(0)->print(pos, Bastet::Color::WhiteBlue, "  ");
    _screen->getDisplay(0)->print(res, Bastet::Color::WhiteMagenta, str);

    return res;
}

void Map::show(const std::vector<Vector2> & pos, const std::string & str)
{
    for (const auto & p : pos)
    {
        if (not valid(p.x, p.y))
        {
            dbgE << "Position [" << p.x << ", " << p.y << "] is not valid";
            continue;
        }

        if (_water[p.x][p.y])
        {
            dbgE << "Position [" << p.x << ", " << p.y << "] is locked";
            continue;
        }

        _screen->getDisplay(0)->print(p, Bastet::Color::WhiteBlue, str);
    }
}

void Map::hide(const std::vector<Vector2> & pos)
{
}

bool Map::valid(int x, int y)
{
    return x >= 0 and y >= 0 and x < _width and y < _height;
}

} // namespace Silver
