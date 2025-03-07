#include "Ship.hpp"
#include "Logger.hpp"
#include "Map.hpp"

namespace Silver {

Ship::Ship(ShipType type, const Vector2 & position, const std::shared_ptr<Map> & map, const std::shared_ptr<Wind> & wind)
    : _type{type}
    , _position{position}
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
{
    _map->push(_position, _arrow[_direction]);

    dbgI << "Insert [" << _position.x << ", " << _position.y << "]";
}

Ship::~Ship()
{
    _map->pop(_position);

    dbgI << "Remove [" << _position.x << ", " << _position.y << "]";
}

int Ship::getDirection() const
{
    return _direction;
}

Vector2 Ship::getPosition() const
{
    return _position;
}

void Ship::turnLeft()
{
    _direction = _direction == 0 ? NUM_DIRECTIONS - 1 : _direction - 1;

    _map->update(_position, _arrow[_direction]);
}

void Ship::turnRight()
{
    _direction = _direction == NUM_DIRECTIONS - 1 ? 0 : _direction + 1;

    _map->update(_position, _arrow[_direction]);
}

void Ship::move()
{
    _position = _map->move(_position, _direction, _arrow[_direction]);

    dbgI << "Move [" << _position.x << ", " << _position.y << "]";
}

void Ship::navigate()
{
    const int shipDirection = _direction;
    const int windDirection = _wind->getDirection();

    dbgW << "Navigate " << "S[" << shipDirection << "] W[" << windDirection << "] C["
         << _course[shipDirection][windDirection] << "]";
}

void Ship::drawWindRose()
{
    const int windDirection = _wind->getDirection();

    // const auto m = 4.3; // 5/4
    // const auto m = 3.0; // 4/3
    // const auto m = 2.5; // 3/2
    // const auto m = 2.1;

    const double a = 1.0;
    const double d = std::sqrt(std::pow(a, 2.0) * 2.0);
    const double x = _speed + _wind->getSpeed();

    for (size_t i = 0; i < NUM_DIRECTIONS; i++)
    {
        std::vector<Vector2> path;
        auto p = _position;
        auto m = 0.0;

        switch (_course[i][windDirection])
        {
            case 0: m = x / 3.5; break;
            case 1: m = x / 5.0; break;
            case 2: m = x / 6.0; break;
            case 3: m = x / 7.0; break;
            case 4: m = 0.0; break;

            default: throw std::runtime_error{"Course to wind is wrong"};
        }

        for (auto n = 0.0; n < m; n += i % 2 ? d : a)
        {
            path.emplace_back(p += _displacement[i]);
        }

        _map->show(path, " 🞄");
    }
}

} // namespace Silver
