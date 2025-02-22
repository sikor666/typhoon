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

int Screen::draw(const Dot & dot, Color color, const std::string & str)
{
    return wattrset(_window, color) == ERR        ? ERR
        : wmove(_window, dot.y, 2 * dot.x) == ERR ? ERR
                                                  : wprintw(_window, str.c_str());
}

void Screen::refresh()
{
    wbkgd(_window, COLOR_PAIR(6));
    wrefresh(_window);
}

} // namespace Bastet
