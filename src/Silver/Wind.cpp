#include "Wind.hpp"
#include "Bastet/Screen.hpp"

namespace Silver {

namespace {
constexpr int MAX_WIND_SPEED = 12;
} // namespace

Wind::Wind(const std::shared_ptr<Bastet::Screen> & screen)
    : _screen{screen}
    , _speed{0}
    , _direction{0}
    , _windRosePos{5, 3}
    , _arrow{"🡡 ", "🡩 ", "🡥 ", "🡭 ", "🡢 ", "🡪 ", "🡦 ", "🡮 ", "🡣 ", "🡫 ", "🡧 ", "🡯 ", "🡠 ", "🡨 ", "🡤 ", "🡬 "}
    , _displacement{Vector2{+0, -1}, Vector2{+1, -1}, Vector2{+1, -0}, Vector2{+1, +1},
                    Vector2{+0, +1}, Vector2{-1, +1}, Vector2{-1, +0}, Vector2{-1, -1}}
{
    const auto & display = _screen->getDisplay(1);

    display->print(_windRosePos, Bastet::Color::BlackWhite, "⎈ ");

    for (size_t i = 0; i < NUM_DIRECTIONS; i++)
    {
        display->print(_windRosePos + _displacement[i], Bastet::Color::BlackWhite, _arrow[i][0]);
        display->print(_windRosePos + _displacement[i] + _displacement[i], Bastet::Color::MagentaWhite, std::to_string(i));
    }
}

Wind::~Wind()
{
}

int Wind::getSpeed() const
{
    return _speed;
}

int Wind::getDirection() const
{
    return _direction;
}

void Wind::setSpeed(int speed)
{
    if (speed < 0 or speed > MAX_WIND_SPEED)
        throw std::runtime_error{"Wind speed is out of range"};

    const auto & display = _screen->getDisplay(1);
    display->print(_windRosePos, Bastet::Color::RedWhite, "  ");
    display->print(_windRosePos, Bastet::Color::RedWhite, std::to_string(speed));

    _speed = speed;
}

void Wind::setDirection(int direction)
{
    if (direction < 0 or direction >= NUM_DIRECTIONS)
        throw std::runtime_error{"Wind direction is out of range"};

    const auto & display = _screen->getDisplay(1);
    display->print(_windRosePos + _displacement[_direction], Bastet::Color::BlackWhite, _arrow[_direction][0]);
    display->print(_windRosePos + _displacement[direction], Bastet::Color::RedWhite, _arrow[direction][1]);

    _direction = direction;
}

} // namespace Silver
