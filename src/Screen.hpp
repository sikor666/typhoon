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
    void RedrawBorder();
    int GetMinX(); /// these are including border
    int GetMinY();
    int GetMaxX();
    int GetMaxY();
    void DrawDot(const Dot & dot, Color color, const std::string & str);
};

} // namespace Bastet
