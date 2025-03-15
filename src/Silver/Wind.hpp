#pragma once

#include "Config.hpp"
#include "Math.hpp"

#include <memory>

namespace Bastet {
class Screen;
} // namespace Bastet

namespace Silver {

class Wind
{
public:
    Wind(const std::shared_ptr<Bastet::Screen> & screen);
    ~Wind();

    int getSpeed() const;
    int getDirection() const;

    void setSpeed(int speed);
    void setDirection(int direction);

private:
    std::shared_ptr<Bastet::Screen> _screen;

    int _speed;
    int _direction;

    Vector2 _windRosePos;
    std::array<std::array<std::string, NUM_ARROW_STYLES>, NUM_DIRECTIONS> _arrow;
    std::array<Vector2, NUM_DIRECTIONS> _displacement;
};

} // namespace Silver
