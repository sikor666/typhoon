#pragma once

#include "Wind.hpp"

#include <memory>

namespace Silver
{

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
    Ship(ShipType type, const Vector2 & position, const std::shared_ptr<Map> & map);
    ~Ship();

    void turnLeft();
    void turnRight();
    void move();

    int getDirection() const;
    Vector2 getPosition() const;

private:
    const ShipType _type;
    Vector2 _position;

    std::shared_ptr<Map> _map;
    std::array<std::string, NUM_DIRECTIONS> _arrows;

    int _resilience;
    int _speed;
    int _maneuver;
    int _direction;
};

} // namespace Silver
