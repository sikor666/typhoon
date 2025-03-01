#pragma once

#include "Math.hpp"

#include <memory>

namespace Bastet
{

class Screen;

} // namespace Bastet

namespace Silver
{

constexpr auto NUM_DIRECTIONS = 8;

class Wind
{
public:
    Wind(const std::shared_ptr<Bastet::Screen> & screen);
    ~Wind();

    void setSpeed(int speed);
    void setDirection(int direction);

private:
    std::shared_ptr<Bastet::Screen> _screen;

    int _speed;
    int _direction;

    Vector2 _windRosePos;
    std::array<std::string, NUM_DIRECTIONS> _arrows;
};

} // namespace Silver
