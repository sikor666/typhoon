#pragma once

#include "Display.hpp"

#include <memory>
#include <vector>

namespace Bastet
{

class Screen
{
public:
    Screen();
    ~Screen();

    int width() const;
    int height() const;

    std::vector<int> getKeys();

    void setWindSpeed(int speed);

    int draw(int x, int y, const std::string & str, Color color);
    void refresh();

private:
    Engine _engine;

    int _width;
    int _height;

    std::vector<std::unique_ptr<Display>> _windows;
};

} // namespace Bastet
