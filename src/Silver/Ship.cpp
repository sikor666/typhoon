#include "Ship.hpp"
#include "Logger.hpp"
#include "Map.hpp"

namespace Silver {

Ship::Ship(ShipType type, const Vector2 & position, const std::shared_ptr<Map> & map, const std::shared_ptr<Wind> & wind)
    : _type{type}
    , _position{position}
    , _map{map}
    , _wind{wind}
    , _arrows{"🡡 ", "🡥 ", "🡢 ", "🡦 ", "🡣 ", "🡧 ", "🡠 ", "🡤 "}
    , _displacements{Vector2{+0, -1}, Vector2{+1, -1}, Vector2{+1, -0}, Vector2{+1, +1}, Vector2{+0, +1}, Vector2{-1, +1},
          Vector2{-1, +0}, Vector2{-1, -1}}
    , _resilience{100}
    , _speed{9}
    , _maneuver{2}
    , _direction{1}
{
    _map->push(_position, _arrows[_direction]);

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

    _map->update(_position, _arrows[_direction]);
}

void Ship::turnRight()
{
    _direction = _direction == NUM_DIRECTIONS - 1 ? 0 : _direction + 1;

    _map->update(_position, _arrows[_direction]);
}

void Ship::move()
{
    _position = _map->move(_position, _direction, _arrows[_direction]);

    dbgI << "Move [" << _position.x << ", " << _position.y << "]";
}

void Ship::navigate()
{
    const int shipDirection = _direction;
    const int windDirection = _wind->getDirection();

    std::array<std::array<int, NUM_DIRECTIONS>, NUM_DIRECTIONS> windCourse{
        0, 1, 2, 3, 4, 3, 2, 1, //
        1, 0, 1, 2, 3, 4, 3, 2, //
        2, 1, 0, 1, 2, 3, 4, 3, //
        3, 2, 1, 0, 1, 2, 3, 4, //
        4, 3, 2, 1, 0, 1, 2, 3, //
        3, 4, 3, 2, 1, 0, 1, 2, //
        2, 3, 4, 3, 2, 1, 0, 1, //
        1, 2, 3, 4, 3, 2, 1, 0, //
    };

    dbgW << "Navigate " << "S[" << shipDirection << "] W[" << windDirection << "] C["
         << windCourse[shipDirection][windDirection] << "]";
}

void Ship::drawWindRose()
{
    // std::array<std::vector<Vector2>, NUM_DIRECTIONS> windRose;

    const auto m = 4.3; // 5/4
    // const auto m = 3.0; // 4/3
    // const auto m = 2.5; // 3/2
    // const auto m = 2.1;
    const auto a = 1.0;
    const auto d = std::sqrt(std::pow(a, 2.0) * 2.0);

    for (size_t i = 0; i < NUM_DIRECTIONS; i++)
    {
        std::vector<Vector2> path;
        auto p = _position;

        for (auto n = 0.0; n <= m; n += i % 2 ? d : a)
        {
            path.emplace_back(p += _displacements[i]);
        }

        _map->show(path, " 🞄");
    }
}

} // namespace Silver
