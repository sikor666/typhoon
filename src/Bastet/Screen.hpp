#pragma once

#include "Block.hpp"
#include "Engine.hpp"

#include <string>

namespace Bastet
{

class Screen
{
public:
    Screen();
    ~Screen();

    int getWidth() const;
    int getHeight() const;

    int draw(const Dot & dot, Color color, const std::string & str);
    void refresh();

private:
    Engine _engine;

    int _width;
    int _height;

    void * _window;
};

} // namespace Bastet
