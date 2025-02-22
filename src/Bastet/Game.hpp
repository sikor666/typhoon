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

    void RedrawWell(BlockType falling, const BlockPosition & pos, const std::string & str);
};

} // namespace Bastet
