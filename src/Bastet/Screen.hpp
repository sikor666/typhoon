#pragma once

#include "Display.hpp"
#include "Math.hpp"

#include <memory>
#include <vector>

namespace Bastet
{

constexpr auto NUM_DIRECTIONS = 8;

class Screen
{
public:
    Screen();
    ~Screen();

    std::vector<int> getKeys();
    const std::unique_ptr<Display> & getDisplay(size_t number) const;

    void setWindSpeed(int speed);
    void setWindDirection(int direction);

    void refresh();

private:
    Engine _engine;

    int _width;
    int _height;

    std::vector<std::unique_ptr<Display>> _displays;
    std::array<std::string, NUM_DIRECTIONS> _arrows;

    Vector2 _windSpeedPos;
};

} // namespace Bastet
