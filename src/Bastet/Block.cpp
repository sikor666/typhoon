#include "Block.hpp"

#include <curses.h>

namespace Bastet
{

BlockArray blocks = { // should be yellow, but I find no portable way to output a yellow solid block character in ncurses.
    BlockImpl{COLOR_PAIR(6), // O
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},
    BlockImpl{COLOR_PAIR(7), // I
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},
    BlockImpl{COLOR_PAIR(1), // Z
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},
    BlockImpl{COLOR_PAIR(5), // T
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},
    BlockImpl{COLOR_PAIR(4), // J
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},
    BlockImpl{COLOR_PAIR(3), // S
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},
    BlockImpl{COLOR_PAIR(2), // L
        DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}}};

const Color GetColor(BlockType b)
{
    return blocks[b].GetColor();
}
const char GetChar(BlockType b)
{
    return "OIZTJSL"[int(b)];
}
} // namespace Bastet
