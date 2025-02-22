#pragma once

#include "Block.hpp"

#include <curses.h>

#include <string>

namespace Bastet
{

class Screen
{
public:
    Screen(int height, int width, int y, int x);
    ~Screen();

    int draw(const Dot & dot, Color color, const std::string & str);
    void refresh();

private:
    WINDOW * _window;
};

} // namespace Bastet
