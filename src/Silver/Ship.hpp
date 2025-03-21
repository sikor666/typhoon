#pragma once

#include "Config.hpp"
#include "Math.hpp"

#include <memory>
#include <vector>

namespace Bastet {
class Screen;
} // namespace Bastet

namespace Silver {

class Map;
class Wind;

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

constexpr std::ostream & operator<<(std::ostream & out, const ShipType & type)
{
    switch (type)
    {
        case Carrack: out << "Carrack"; break;
        case Galleon: out << "Galleon"; break;
        case Frigate: out << "Frigate"; break;
        case Brigantine: out << "Brigantine"; break;
        case Caravel: out << "Caravel"; break;
        case Sloop: out << "Sloop"; break;
        case Pinnace: out << "Pinnace"; break;

        default: break;
    }

    return out;
}

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
    void hideCourse();

private:
    const ShipType _type;

    Vector2 _position;
    Vector2 _shipRosePos;

    std::shared_ptr<Bastet::Screen> _screen;
    std::shared_ptr<Map> _map;
    std::shared_ptr<Wind> _wind;

    std::array<Vector2, NUM_DIRECTIONS> _displacement;
    std::array<std::string, NUM_DIRECTIONS> _arrow;
    std::array<std::vector<Vector2>, NUM_DIRECTIONS> _range;
    std::array<std::array<int, NUM_DIRECTIONS>, NUM_DIRECTIONS> _course;

    int _resilience;
    int _speed;
    int _maneuver;
    int _direction;
    double _distance;
    bool _active;
};

} // namespace Silver
