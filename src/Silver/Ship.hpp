#pragma once

#include "Wind.hpp"

#include <memory>
#include <vector>

namespace Bastet {
class Screen;
} // namespace Bastet

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
    Ship(ShipType type, const Vector2 & position, const std::shared_ptr<Bastet::Screen> & screen,
         const std::shared_ptr<Map> & map, const std::shared_ptr<Wind> & wind);
    ~Ship();

    void activate();
    void deactivate();

    void turnLeft();
    void turnRight();

    void move();
    void navigate();
    void showCourse();

private:
    const ShipType _type;
    Vector2 _position;
    Vector2 _shipRosePos;

    std::shared_ptr<Bastet::Screen> _screen;
    std::shared_ptr<Map> _map;
    std::shared_ptr<Wind> _wind;

    std::array<std::string, NUM_DIRECTIONS> _arrow;
    std::array<Vector2, NUM_DIRECTIONS> _displacement;
    std::array<std::array<int, NUM_DIRECTIONS>, NUM_DIRECTIONS> _course;
    std::vector<Vector2> _path;

    int _resilience;
    int _speed;
    int _maneuver;
    int _direction;

    double _side;
    double _diagonal;
    double _distance;

    bool _active;
};

} // namespace Silver
