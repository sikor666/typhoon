#include "Display.hpp"

#include <curses.h>

namespace Bastet
{

Display::Display(int x, int y, int w, int h, Color color)
    : _width{w}
    , _height{h}
    , _window{newwin(_height, _width, y, x)}
{
    wbkgd(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(color));
}

Display::~Display()
{
    delwin(reinterpret_cast<WINDOW *>(_window));
}

int Display::width() const
{
    return _width / 2;
}

int Display::height() const
{
    return _height;
}

int Display::print(Vector2 position, Color color, const std::string & str)
{
    return wattrset(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(color)) == ERR ? ERR
        : wmove(reinterpret_cast<WINDOW *>(_window), position.y, 2 * position.x) == ERR
        ? ERR
        : wprintw(reinterpret_cast<WINDOW *>(_window), str.c_str());
}

int Display::refresh()
{
    return wrefresh(reinterpret_cast<WINDOW *>(_window));
}

} // namespace Bastet
