#pragma once

#include "Block.hpp"

#include <curses.h>

namespace Bastet
{

class BorderedWindow
{
private:
    WINDOW * _window;
    WINDOW * _border;

public:
    BorderedWindow(
        int height, int width, int y = -1, int x = -1); /// w and h are "inner" dimensions, excluding the border. y and x
                                                        /// are "outer", including the border. y=-1,x=-1 means "center"
    ~BorderedWindow();
    operator WINDOW *(); // returns the inner window
    void RedrawBorder();
    int GetMinX(); /// these are including border
    int GetMinY();
    int GetMaxX();
    int GetMaxY();
    void DrawDot(const Dot & d, Color c);
};

} // namespace Bastet
