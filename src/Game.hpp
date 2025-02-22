#pragma once

#include "Screen.hpp"
#include "Well.hpp"

namespace Bastet
{

class Game
{
public:
    Game();

    void Play();

private:
    int _width;
    int _height;

    Well _well;
    Screen _screen;

    // std::vector<std::vector<Color>> _colors;

    void RedrawWell(BlockType falling, const BlockPosition & pos, const std::string & str);
};

} // namespace Bastet
