#pragma once

#include "Engine.hpp"

#include <string>
#include <vector>

namespace Bastet
{

class Screen
{
public:
    Screen();
    ~Screen();

    int getWidth() const;
    int getHeight() const;

    std::vector<int> getKeys();

    int draw(int x, int y, int color, const std::string & str);
    void refresh();

private:
    Engine _engine;

    int _width;
    int _height;

    void * _window;
};

} // namespace Bastet
