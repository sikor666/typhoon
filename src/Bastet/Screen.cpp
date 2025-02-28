#include "Screen.hpp"
#include "Logger.hpp"

#include <curses.h>

namespace Bastet
{

Screen::Screen()
    : _engine{}
    , _width{getmaxx(stdscr)}
    , _height{getmaxy(stdscr)}
    , _displays{}
    , _arrows{"🡩 ", "🡭 ", "🡪 ", "🡮 ", "🡫 ", "🡯 ", "🡨 ", "🡬 "}
    , _windSpeedPos{5, 2}
{
    _displays.emplace_back(std::make_unique<Display>(0, 0, _width - 20, _height, Color::WhiteBlue));
    _displays.emplace_back(std::make_unique<Display>(_width - 20, 0, 20, _height, Color::BlackWhite));

    _displays[1]->print(_windSpeedPos.x - 1, _windSpeedPos.y - 1, Color::BlackWhite, "🡤 ");
    _displays[1]->print(_windSpeedPos.x + 0, _windSpeedPos.y - 1, Color::BlackWhite, "🡡 ");
    _displays[1]->print(_windSpeedPos.x + 1, _windSpeedPos.y - 1, Color::BlackWhite, "🡥 ");
    _displays[1]->print(_windSpeedPos.x - 1, _windSpeedPos.y + 0, Color::BlackWhite, "🡠 ");
    _displays[1]->print(_windSpeedPos.x + 0, _windSpeedPos.y + 0, Color::BlackWhite, "❅ ");
    _displays[1]->print(_windSpeedPos.x + 1, _windSpeedPos.y + 0, Color::BlackWhite, "🡢 ");
    _displays[1]->print(_windSpeedPos.x - 1, _windSpeedPos.y + 1, Color::BlackWhite, "🡧 ");
    _displays[1]->print(_windSpeedPos.x + 0, _windSpeedPos.y + 1, Color::BlackWhite, "🡣 ");
    _displays[1]->print(_windSpeedPos.x + 1, _windSpeedPos.y + 1, Color::BlackWhite, "🡦 ");

    dbgI << "Screen size [" << width() << ", " << height() << "]";
}

Screen::~Screen()
{
}

int Screen::width() const
{
    return _displays[0]->width();
}

int Screen::height() const
{
    return _displays[0]->height();
}

std::vector<int> Screen::getKeys()
{
    std::vector<int> keys;

    int key;
    while ((key = getch()) != ERR)
        keys.push_back(key);

    return keys;
}

void Screen::setWindSpeed(int speed)
{
    _displays[1]->print(5, 2, Color::RedWhite, std::to_string(speed));
}

void Screen::setWindDirection(int direction)
{
    switch (direction)
    {
        case 0: _displays[1]->print(_windSpeedPos.x + 0, _windSpeedPos.y - 1, Color::RedWhite, _arrows[0]); break;
        case 1: _displays[1]->print(_windSpeedPos.x + 1, _windSpeedPos.y - 1, Color::RedWhite, _arrows[1]); break;
        case 2: _displays[1]->print(_windSpeedPos.x + 1, _windSpeedPos.y + 0, Color::RedWhite, _arrows[2]); break;
        case 3: _displays[1]->print(_windSpeedPos.x + 1, _windSpeedPos.y + 1, Color::RedWhite, _arrows[3]); break;
        case 4: _displays[1]->print(_windSpeedPos.x + 0, _windSpeedPos.y + 1, Color::RedWhite, _arrows[4]); break;
        case 5: _displays[1]->print(_windSpeedPos.x - 1, _windSpeedPos.y + 1, Color::RedWhite, _arrows[5]); break;
        case 6: _displays[1]->print(_windSpeedPos.x - 1, _windSpeedPos.y + 0, Color::RedWhite, _arrows[6]); break;
        case 7: _displays[1]->print(_windSpeedPos.x - 1, _windSpeedPos.y - 1, Color::RedWhite, _arrows[7]); break;

        default: break;
    }
}

int Screen::draw(int x, int y, const std::string & str, Color color)
{
    return _displays[0]->print(x, y, color, str);
}

void Screen::refresh()
{
    for (const auto & display : _displays)
        display->refresh();
}

} // namespace Bastet
