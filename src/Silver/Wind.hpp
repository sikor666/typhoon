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
constexpr auto NUM_ARROW_STYLES = 2;

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
    std::array<std::array<std::string, NUM_ARROW_STYLES>, NUM_DIRECTIONS> _arrows;
    std::array<Vector2, NUM_DIRECTIONS> _displacements;
};

} // namespace Silver
