#include "Screen.hpp"
#include "Logger.hpp"

#include <curses.h>

namespace Bastet
{

Screen::Screen()
    : _engine{}
    , _width{getmaxx(stdscr)}
    , _height{getmaxy(stdscr)}
    , _window{newwin(_height, _width - 20, 0, 0)}
    , _panel{newwin(_height, 20, 0, _width - 20)}
{
    dbgI << "Screen size [" << _width << ", " << _height << "]";

    wbkgd(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(Color::WhiteBlue));
    wbkgd(reinterpret_cast<WINDOW *>(_panel), COLOR_PAIR(Color::BlackWhite));

    auto print = [this](int x, int y, const std::string & str) {
        return wmove(reinterpret_cast<WINDOW *>(_panel), y, 2 * x) == ERR
            ? ERR
            : wprintw(reinterpret_cast<WINDOW *>(_panel), str.c_str());
    };

    print(4, 1, "🡤 ");
    print(5, 1, "🡡 ");
    print(6, 1, "🡥 ");
    print(4, 2, "🡠 ");
    print(5, 2, "❅ ");
    print(6, 2, "🡢 ");
    print(4, 3, "🡧 ");
    print(5, 3, "🡣 ");
    print(6, 3, "🡦 ");
}

Screen::~Screen()
{
    delwin(reinterpret_cast<WINDOW *>(_window));
    delwin(reinterpret_cast<WINDOW *>(_panel));
}

int Screen::getWidth() const
{
    return _width / 2 - 10;
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

int Screen::draw(int x, int y, Color color, const std::string & str)
{
    return wattrset(reinterpret_cast<WINDOW *>(_window), COLOR_PAIR(color)) == ERR ? ERR
        : wmove(reinterpret_cast<WINDOW *>(_window), y, 2 * x) == ERR
        ? ERR
        : wprintw(reinterpret_cast<WINDOW *>(_window), str.c_str());
}

void Screen::refresh()
{
    wrefresh(reinterpret_cast<WINDOW *>(_window));
    wrefresh(reinterpret_cast<WINDOW *>(_panel));
}

} // namespace Bastet
