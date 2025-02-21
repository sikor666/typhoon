#include "Screen.hpp"

namespace Bastet
{

Screen::Screen(int height, int width, int y, int x)
{
    _window = newwin(height, width, y, x);
}

Screen::~Screen()
{
    delwin(_window);
}

Screen::operator WINDOW *()
{
    return _window;
}

void Screen::RedrawBorder()
{
    box(_window, 0, 0);
    wrefresh(_window);
}

int Screen::GetMinX()
{
    int x, y;
    getbegyx(_window, y, x);
    (void)(y); // silence warning about unused y
    return x;
}

int Screen::GetMinY()
{
    int y, x;
    getbegyx(_window, y, x);
    return y;
}

int Screen::GetMaxX()
{
    int x, y;
    getmaxyx(_window, y, x);
    (void)(y); // silence warning about unused y
    return GetMinX() + x;
}

int Screen::GetMaxY()
{
    int y, x;
    getmaxyx(_window, y, x);
    return GetMinY() + y;
}

void Screen::DrawDot(const Dot & dot, Color color, const std::string & str)
{
    wattrset((WINDOW *)(*this), color);
    // mvwaddch(*this, dot.y, 2 * dot.x, ' ');
    // mvwaddch(*this, dot.y, 2 * dot.x + 1, ' ');

    wmove(*this, dot.y, 2 * dot.x) == ERR ? ERR : wprintw(*this, str.c_str());
}

} // namespace Bastet
