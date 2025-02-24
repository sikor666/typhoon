#pragma once

#include <memory>

namespace Silver
{

constexpr auto NUM_DIRECTIONS = 8;

class Map;

class Ship
{
public:
    Ship(const std::shared_ptr<Map> & map);
    ~Ship();

    void turnLeft();
    void turnRight();
    void move();

    void setPosition(int x, int y);

    int getDirection() const;
    int getX() const;
    int getY() const;

private:
    std::shared_ptr<Map> _map;
    std::array<std::string, NUM_DIRECTIONS> _arrows;

    int _direction;

    int _x;
    int _y;
};

} // namespace Silver
