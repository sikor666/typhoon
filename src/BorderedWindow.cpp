#include "BorderedWindow.hpp"

namespace Bastet
{

BorderedWindow::BorderedWindow(int height, int width, int y, int x)
{
    if (y == -1 || x == -1)
    {
        int screen_h, screen_w;
        getmaxyx(stdscr, screen_h, screen_w);
        if (y == -1)
            y = (screen_h - height - 2) / 2 - 1;
        if (x == -1)
            x = (screen_w - width - 2) / 2 - 1;
    }
    _border = newwin(height + 2, width + 2, y, x);
    _window = derwin(_border, height, width, 1, 1);
    // wattrset(_border, COLOR_PAIR(5));
    // RedrawBorder();
}

BorderedWindow::~BorderedWindow()
{
    delwin(_window);
    delwin(_border);
}

BorderedWindow::operator WINDOW *()
{
    return _window;
}

void BorderedWindow::RedrawBorder()
{
    box(_border, 0, 0);
    wrefresh(_border);
}

int BorderedWindow::GetMinX()
{
    int x, y;
    getbegyx(_border, y, x);
    (void)(y); // silence warning about unused y
    return x;
}

int BorderedWindow::GetMinY()
{
    int y, x;
    getbegyx(_border, y, x);
    return y;
}

int BorderedWindow::GetMaxX()
{
    int x, y;
    getmaxyx(_border, y, x);
    (void)(y); // silence warning about unused y
    return GetMinX() + x;
}

int BorderedWindow::GetMaxY()
{
    int y, x;
    getmaxyx(_border, y, x);
    return GetMinY() + y;
}

void BorderedWindow::DrawDot(const Dot & d, Color c)
{
    wattrset((WINDOW *)(*this), c);
    mvwaddch(*this, d.y, 2 * d.x, ' ');
    mvwaddch(*this, d.y, 2 * d.x + 1, ' ');
}

} // namespace Bastet
