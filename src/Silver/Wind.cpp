#include "Wind.hpp"
#include "Bastet/Screen.hpp"

namespace Silver
{

Wind::Wind(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _windRosePos{5, 2}
    , _arrows{"🡡 ", "🡩 ", "🡥 ", "🡭 ", "🡢 ", "🡪 ", "🡦 ", "🡮 ", "🡣 ", "🡫 ", "🡧 ", "🡯 ", "🡠 ", "🡨 ", "🡤 ", "🡬 "}
{
    const auto & display = _screen->getDisplay(1);

    display->print(_windRosePos.x + 0, _windRosePos.y + 0, Bastet::Color::BlackWhite, "⎈ ");
    display->print(_windRosePos.x + 0, _windRosePos.y - 1, Bastet::Color::BlackWhite, _arrows[0][0]);
    display->print(_windRosePos.x + 1, _windRosePos.y - 1, Bastet::Color::BlackWhite, _arrows[1][0]);
    display->print(_windRosePos.x + 1, _windRosePos.y + 0, Bastet::Color::BlackWhite, _arrows[2][0]);
    display->print(_windRosePos.x + 1, _windRosePos.y + 1, Bastet::Color::BlackWhite, _arrows[3][0]);
    display->print(_windRosePos.x + 0, _windRosePos.y + 1, Bastet::Color::BlackWhite, _arrows[4][0]);
    display->print(_windRosePos.x - 1, _windRosePos.y + 1, Bastet::Color::BlackWhite, _arrows[5][0]);
    display->print(_windRosePos.x - 1, _windRosePos.y + 0, Bastet::Color::BlackWhite, _arrows[6][0]);
    display->print(_windRosePos.x - 1, _windRosePos.y - 1, Bastet::Color::BlackWhite, _arrows[7][0]);
}

Wind::~Wind()
{
}

void Wind::setSpeed(int speed)
{
    _screen->getDisplay(1)->print(5, 2, Bastet::Color::RedWhite, std::to_string(speed));
}

void Wind::setDirection(int direction)
{
    const auto & display = _screen->getDisplay(1);

    switch (direction)
    {
        case 0: display->print(_windRosePos.x + 0, _windRosePos.y - 1, Bastet::Color::RedWhite, _arrows[0][1]); break;
        case 1: display->print(_windRosePos.x + 1, _windRosePos.y - 1, Bastet::Color::RedWhite, _arrows[1][1]); break;
        case 2: display->print(_windRosePos.x + 1, _windRosePos.y + 0, Bastet::Color::RedWhite, _arrows[2][1]); break;
        case 3: display->print(_windRosePos.x + 1, _windRosePos.y + 1, Bastet::Color::RedWhite, _arrows[3][1]); break;
        case 4: display->print(_windRosePos.x + 0, _windRosePos.y + 1, Bastet::Color::RedWhite, _arrows[4][1]); break;
        case 5: display->print(_windRosePos.x - 1, _windRosePos.y + 1, Bastet::Color::RedWhite, _arrows[5][1]); break;
        case 6: display->print(_windRosePos.x - 1, _windRosePos.y + 0, Bastet::Color::RedWhite, _arrows[6][1]); break;
        case 7: display->print(_windRosePos.x - 1, _windRosePos.y - 1, Bastet::Color::RedWhite, _arrows[7][1]); break;

        default: break;
    }
}

} // namespace Silver
