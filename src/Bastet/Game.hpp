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
    Screen _screen;
    Well _well;

    void RedrawWell(BlockType falling, const BlockPosition & pos, const std::string & str);
};

} // namespace Bastet
