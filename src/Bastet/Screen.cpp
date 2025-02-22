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

int Screen::draw(const Dot & dot, Color color, const std::string & str)
{
    return wattrset(*this, color) == ERR ? ERR : wmove(*this, dot.y, 2 * dot.x) == ERR ? ERR : wprintw(*this, str.c_str());
}

void Screen::refresh()
{
    wbkgd(*this, COLOR_PAIR(6));
    wrefresh(*this);
}

} // namespace Bastet
