#pragma once

#include "Math.hpp"

#include <memory>

namespace Silver
{

constexpr auto NUM_DIRECTIONS = 8;

class Map;

enum ShipType
{
    Carrack,
    Galleon,
    Frigate,
    Brigantine,
    Caravel,
    Sloop,
    Pinnace,
};

class Ship
{
public:
    Ship(const std::shared_ptr<Map> & map);
    ~Ship();

    void turnLeft();
    void turnRight();
    void move();

    int getDirection() const;
    Vector2 getPosition() const;

private:
    std::shared_ptr<Map> _map;
    std::array<std::string, NUM_DIRECTIONS> _arrows;

    int _speed;
    int _maneuver;

    int _direction;
    Vector2 _position;
};

} // namespace Silver
