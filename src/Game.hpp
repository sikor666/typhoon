#pragma once

#include "BorderedWindow.hpp"
#include "Curses.hpp"
#include "Well.hpp"

namespace Bastet
{

class Game
{
public:
    Game();

    void RedrawWell(const Well * well, BlockType falling, const BlockPosition & pos);
    void Play();

private:
    int _width;
    int _height;

    Curses _curses;
    Well _well;
    BorderedWindow _wellWin;

    std::vector<std::vector<Color>> _colors;
};

} // namespace Bastet
