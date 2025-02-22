#pragma once

#include "Block.hpp"

#include <string>

namespace Bastet
{

class Screen
{
public:
    Screen(int height, int width, int y, int x);
    ~Screen();

    int getWidth() const;
    int getHeight() const;

    int draw(const Dot & dot, Color color, const std::string & str);
    void refresh();

private:
    int _width;
    int _height;

    void * _window;
};

} // namespace Bastet
