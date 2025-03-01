#include "Screen.hpp"
#include "Logger.hpp"

#include <curses.h>

namespace Bastet
{

Screen::Screen()
    : _engine{}
    , _width{getmaxx(stdscr)}
    , _height{getmaxy(stdscr)}
    , _displays{}
{
    _displays.emplace_back(std::make_unique<Display>(0, 0, _width - 20, _height, Color::WhiteBlue));
    _displays.emplace_back(std::make_unique<Display>(_width - 20, 0, 20, _height, Color::BlackWhite));

    dbgI << "Screen size [" << _width / 2 << ", " << _height << "]";
}

Screen::~Screen()
{
}

std::vector<int> Screen::getKeys()
{
    std::vector<int> keys;

    int key;
    while ((key = getch()) != ERR)
        keys.push_back(key);

    return keys;
}

const std::unique_ptr<Display> & Screen::getDisplay(size_t number) const
{
    if (number >= _displays.size())
        throw std::runtime_error{"Display number is out of range"};

    return _displays[number];
}

void Screen::refresh()
{
    for (const auto & display : _displays)
        display->refresh();
}

} // namespace Bastet
