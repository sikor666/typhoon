#include "Screen.hpp"

#include <curses.h>

namespace Bastet
{

Screen::Screen(int height, int width, int y, int x)
{
    _window = newwin(height, width, y, x);
}

Screen::~Screen()
{
    delwin(reinterpret_cast<WINDOW *>(_window));
}

int Screen::draw(const Dot & dot, Color color, const std::string & str)
{
    return wattrset(reinterpret_cast<WINDOW *>(_window), color) == ERR ? ERR
        : wmove(reinterpret_cast<WINDOW *>(_window), dot.y, 2 * dot.x) == ERR
        ? ERR
        : wprintw(reinterpret_cast<WINDOW *>(_window), str.c_str());
}

void Screen::refresh()
{
    wbkgd(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(6));
    wrefresh(reinterpret_cast<WINDOW *>(_window));
}

} // namespace Bastet
