#include "Screen.hpp"
#include "Logger.hpp"

#include <curses.h>

namespace Bastet
{

Screen::Screen()
    : _engine{}
    , _width{getmaxx(stdscr)}
    , _height{getmaxy(stdscr)}
{
    _windows.emplace_back(std::make_unique<Display>(0, 0, _width - 20, _height, Color::WhiteBlue));
    _windows.emplace_back(std::make_unique<Display>(_width - 20, 0, 20, _height, Color::BlackWhite));

    _windows[1]->print(4, 1, Color::BlackWhite, "🡤 ");
    _windows[1]->print(5, 1, Color::BlackWhite, "🡡 ");
    _windows[1]->print(6, 1, Color::BlackWhite, "🡥 ");
    _windows[1]->print(4, 2, Color::BlackWhite, "🡠 ");
    _windows[1]->print(5, 2, Color::BlackWhite, "❅ ");
    _windows[1]->print(6, 2, Color::BlackWhite, "🡢 ");
    _windows[1]->print(4, 3, Color::BlackWhite, "🡧 ");
    _windows[1]->print(5, 3, Color::BlackWhite, "🡣 ");
    _windows[1]->print(6, 3, Color::BlackWhite, "🡦 ");

    dbgI << "Screen size [" << width() << ", " << height() << "]";
}

Screen::~Screen()
{
}

int Screen::width() const
{
    return _windows[0]->width();
}

int Screen::height() const
{
    return _windows[0]->height();
}

std::vector<int> Screen::getKeys()
{
    std::vector<int> keys;

    int key;
    while ((key = getch()) != ERR)
        keys.push_back(key);

    return keys;
}

int Screen::draw(int x, int y, const std::string & str, Color color)
{
    return _windows[0]->print(x, y, color, str);
}

void Screen::refresh()
{
    for (const auto & w : _windows)
        w->refresh();
}

} // namespace Bastet
