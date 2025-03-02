#include "Wind.hpp"
#include "Bastet/Screen.hpp"

namespace Silver
{

Wind::Wind(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _speed{0}
    , _direction{0}
    , _windRosePos{5, 2}
    , _arrows{"🡡 ", "🡩 ", "🡥 ", "🡭 ", "🡢 ", "🡪 ", "🡦 ", "🡮 ", "🡣 ", "🡫 ", "🡧 ", "🡯 ", "🡠 ", "🡨 ", "🡤 ", "🡬 "}
    , _displacements{Vector2{+0, -1}, Vector2{+1, -1}, Vector2{+1, -0}, Vector2{+1, +1}, Vector2{+0, +1}, Vector2{-1, +1},
          Vector2{-1, +0}, Vector2{-1, -1}}
{
    const auto & display = _screen->getDisplay(1);

    display->print(_windRosePos, Bastet::Color::BlackWhite, "⎈ ");

    for (size_t i = 0; i < NUM_DIRECTIONS; i++)
        display->print(_windRosePos + _displacements[i], Bastet::Color::BlackWhite, _arrows[i][0]);
}

Wind::~Wind()
{
}

void Wind::setSpeed(int speed)
{
    _screen->getDisplay(1)->print(_windRosePos, Bastet::Color::RedWhite, std::to_string(speed));
}

void Wind::setDirection(int direction)
{
    const auto & display = _screen->getDisplay(1);

    if (direction < 0 or direction >= NUM_DIRECTIONS)
        throw std::runtime_error{"Direction is out of range"};

    display->print(_windRosePos + _displacements[_direction], Bastet::Color::BlackWhite, _arrows[_direction][0]);
    display->print(_windRosePos + _displacements[direction], Bastet::Color::RedWhite, _arrows[direction][1]);

    _direction = direction;
}

} // namespace Silver
