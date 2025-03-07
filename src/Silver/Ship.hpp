#pragma once

#include "Wind.hpp"

#include <memory>

namespace Silver {

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
    Ship(ShipType type, const Vector2 & position, const std::shared_ptr<Map> & map, const std::shared_ptr<Wind> & wind);
    ~Ship();

    int getDirection() const;
    Vector2 getPosition() const;

    void turnLeft();
    void turnRight();
    void move();
    void navigate();

    void drawWindRose();

private:
    const ShipType _type;
    Vector2 _position;

    std::shared_ptr<Map> _map;
    std::shared_ptr<Wind> _wind;
    std::array<std::string, NUM_DIRECTIONS> _arrow;
    std::array<Vector2, NUM_DIRECTIONS> _displacement;
    std::array<std::array<int, NUM_DIRECTIONS>, NUM_DIRECTIONS> _course;

    int _resilience;
    int _speed;
    int _maneuver;
    int _direction;
};

} // namespace Silver
