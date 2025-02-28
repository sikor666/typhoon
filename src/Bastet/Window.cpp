#include "Window.hpp"

#include <curses.h>

namespace Bastet
{

Window::Window(int x, int y, int w, int h, Color color)
    : _width{w}
    , _height{h}
    , _window{newwin(_height, _width, y, x)}
{
    wbkgd(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(color));
}

Window::~Window()
{
    delwin(reinterpret_cast<WINDOW *>(_window));
}

int Window::width() const
{
    return _width / 2;
}

int Window::height() const
{
    return _height;
}

int Window::print(int x, int y, Color color, const std::string & str)
{
    return wattrset(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(color)) == ERR ? ERR
        : wmove(reinterpret_cast<WINDOW *>(_window), y, 2 * x) == ERR
        ? ERR
        : wprintw(reinterpret_cast<WINDOW *>(_window), str.c_str());
}

int Window::refresh()
{
    return wrefresh(reinterpret_cast<WINDOW *>(_window));
}

} // namespace Bastet
