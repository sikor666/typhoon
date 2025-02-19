#pragma once

#include "Screen.hpp"
#include "Well.hpp"

namespace Bastet
{

class Game
{
public:
    Game();

    void DropBlock(Well * well, BlockType blockType);
    void RedrawWell(Well * well, BlockType falling, const BlockPosition & pos);
    void Play();

private:
    int _width;
    int _height;

    Well _well;
    Screen _screen;

    std::vector<std::vector<Color>> _colors;
};

} // namespace Bastet
