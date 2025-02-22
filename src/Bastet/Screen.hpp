#pragma once

#include "Block.hpp"

#include <curses.h>

#include <string>

namespace Bastet
{

class Screen
{
private:
    WINDOW * _window;

public:
    Screen(int height, int width, int y, int x);
    ~Screen();

    operator WINDOW *(); // returns the inner window

    int DrawDot(const Dot & dot, Color color, const std::string & str);
};

} // namespace Bastet
