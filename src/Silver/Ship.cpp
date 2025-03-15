#include "Ship.hpp"
#include "Bastet/Screen.hpp"
#include "Logger.hpp"
#include "Map.hpp"
#include "Wind.hpp"

#include <iomanip>

namespace Silver {

Ship::Ship(ShipType type, const Vector2 & position, const std::shared_ptr<Bastet::Screen> & screen,
           const std::shared_ptr<Map> & map, const std::shared_ptr<Wind> & wind)
    : _type{type}
    , _position{position}
    , _shipRosePos{5, 10}
    , _screen{screen}
    , _map{map}
    , _wind{wind}
    , _arrow{"🡡 ", "🡥 ", "🡢 ", "🡦 ", "🡣 ", "🡧 ", "🡠 ", "🡤 "}
    , _displacement{Vector2{+0, -1}, Vector2{+1, -1}, Vector2{+1, -0}, Vector2{+1, +1},
                    Vector2{+0, +1}, Vector2{-1, +1}, Vector2{-1, +0}, Vector2{-1, -1}}
    , _course{0, 1, 2, 3, 4, 3, 2, 1, //
              1, 0, 1, 2, 3, 4, 3, 2, //
              2, 1, 0, 1, 2, 3, 4, 3, //
              3, 2, 1, 0, 1, 2, 3, 4, //
              4, 3, 2, 1, 0, 1, 2, 3, //
              3, 4, 3, 2, 1, 0, 1, 2, //
              2, 3, 4, 3, 2, 1, 0, 1, //
              1, 2, 3, 4, 3, 2, 1, 0}
    , _resilience{100}
    , _speed{9}
    , _maneuver{2}
    , _direction{1}
    , _side{1.0}
    , _diagonal{std::sqrt(std::pow(_side, 2.0) * 2.0)}
    , _distance{0.0}
    , _active{false}
{
    _map->push(_position, _arrow[_direction]);

    dbgI << "Insert [" << _position.x << ", " << _position.y << "]";
}

Ship::~Ship()
{
    _map->pop(_position);

    dbgI << "Remove [" << _position.x << ", " << _position.y << "]";
}

void Ship::activate()
{
    _active = true;

    _map->update(_position, _active, _arrow[_direction]);

    dbgI << "Activate [" << _active << "]";
}

void Ship::deactivate()
{
    _active = false;

    _map->update(_position, _active, _arrow[_direction]);

    dbgI << "Deactivate [" << _active << "]";
}

void Ship::turnLeft()
{
    _direction = _direction == 0 ? NUM_DIRECTIONS - 1 : _direction - 1;

    _map->update(_position, _active, _arrow[_direction]);

    dbgI << "Left [" << _arrow[_direction] << "]";
}

void Ship::turnRight()
{
    _direction = _direction == NUM_DIRECTIONS - 1 ? 0 : _direction + 1;

    _map->update(_position, _active, _arrow[_direction]);

    dbgI << "Right [" << _arrow[_direction] << "]";
}

void Ship::move()
{
    _distance += _direction % 2 ? _diagonal : _side;

    _position = _map->move(_position, _direction, _arrow[_direction]);

    dbgI << "Move [" << _position.x << ", " << _position.y << "] [" << _distance << "]";
}

void Ship::navigate()
{
    const int shipDirection = _direction;
    const int windDirection = _wind->getDirection();

    dbgW << "Navigate " << "S[" << shipDirection << "] W[" << windDirection << "] C["
         << _course[shipDirection][windDirection] << "]";
}

void Ship::showCourse()
{
    const auto windDirection = _wind->getDirection();
    const auto windSpeed = _wind->getSpeed();
    const auto & display = _screen->getDisplay(1);

    const double x = _speed + windSpeed;

    _distance = 0.0;

    display->print(_shipRosePos, Bastet::Color::RedWhite, std::to_string(_speed));

    _map->show(_path, "  ");
    _path.clear();

    for (int i = 0; i < NUM_DIRECTIONS; i++)
    {
        auto p = _position;
        auto w = _course[i][windDirection];
        auto m = 0.0;

        switch (w)
        {
            case 0: m = 3.5; break;      // 0
            case 1: m = 4.5; break;      // 45
            //      m = 5.0; break;      // 60
            case 2: m = 6.0; break;      // 90
            //      m = 7.0; break;      // 120
            case 3: m = 8.0; break;      // 135
            case 4: m = INFINITY; break; // 180

            default: throw std::runtime_error{"Course to wind is wrong"};
        }

        const auto r = x / m;

        std::stringstream stream;
        stream << i << ": (" << _speed << "+" << windSpeed << ")/" << std::fixed << std::setprecision(1) << m << "=" << r;
        display->print(Vector2{1, 15 + static_cast<float>(i)}, Bastet::Color::BlackWhite, "                  ");
        display->print(Vector2{1, 15 + static_cast<float>(i)}, Bastet::Color::BlackWhite, stream.str());

        display->print(_shipRosePos + _displacement[i], Bastet::Color::BlackWhite, std::to_string(w));

        const size_t v = static_cast<bool>(i % 2) ? std::floor(r / _diagonal + 0.4) : std::floor(r / _side);

        for (size_t n = 0; n < v; n++)
        {
            _path.emplace_back(p += _displacement[i]);
        }
    }

    _path = _map->show(_path, " 🞄");
}

} // namespace Silver
