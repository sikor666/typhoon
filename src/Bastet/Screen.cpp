#include "Screen.hpp"

#include <curses.h>

namespace Bastet
{

Screen::Screen()
    : _engine{}
    , _width{getmaxx(stdscr)}
    , _height{getmaxy(stdscr)}
{
    _window = newwin(_height, _width, 0, 0);
}

Screen::~Screen()
{
    delwin(reinterpret_cast<WINDOW *>(_window));
}

int Screen::getWidth() const
{
    return _width;
}

int Screen::getHeight() const
{
    return _height;
}

std::vector<int> Screen::getKeys()
{
    std::vector<int> keys;

    int key;
    while ((key = getch()) != ERR)
        keys.push_back(key);

    return keys;
}

int Screen::draw(int x, int y, int color, const std::string & str)
{
    return wattrset(reinterpret_cast<WINDOW *>(_window), color) == ERR ? ERR
        : wmove(reinterpret_cast<WINDOW *>(_window), y, 2 * x) == ERR
        ? ERR
        : wprintw(reinterpret_cast<WINDOW *>(_window), str.c_str());
}

void Screen::refresh()
{
    wbkgd(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(6));
    wrefresh(reinterpret_cast<WINDOW *>(_window));
}

} // namespace Bastet
