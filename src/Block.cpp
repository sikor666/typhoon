#include "Block.hpp"

#include <curses.h>

namespace Bastet
{

BlockArray blocks = { // should be yellow, but I find no portable way to output a yellow solid block character in ncurses.
    BlockImpl{COLOR_PAIR(7),
        OrientationMatrix{// O
            DotMatrix{    // orientation 0 (initial)
                Dot{1, 1}, Dot{2, 1}, Dot{1, 0}, Dot{2, 0}},
            DotMatrix{// orientation 1
                Dot{1, 1}, Dot{2, 1}, Dot{1, 0}, Dot{2, 0}},
            DotMatrix{// orientation 2
                Dot{1, 1}, Dot{2, 1}, Dot{1, 0}, Dot{2, 0}},
            DotMatrix{// orientation 3
                Dot{1, 1}, Dot{2, 1}, Dot{1, 0}, Dot{2, 0}}}},
    BlockImpl{COLOR_PAIR(4),
        OrientationMatrix{// I
            DotMatrix{    // orientation 0 (initial)
                Dot{0, 1}, Dot{1, 1}, Dot{2, 1}, Dot{3, 1}},
            DotMatrix{// orientation 1
                Dot{2, 3}, Dot{2, 1}, Dot{2, 2}, Dot{2, 0}},
            DotMatrix{// orientation 2
                Dot{0, 2}, Dot{1, 2}, Dot{2, 2}, Dot{3, 2}},
            DotMatrix{// orientation 3
                Dot{1, 3}, Dot{1, 1}, Dot{1, 2}, Dot{1, 0}}}},
    BlockImpl{COLOR_PAIR(1),
        OrientationMatrix{// Z
            DotMatrix{    // orientation 0 (initial)
                Dot{1, 1}, Dot{2, 1}, Dot{0, 0}, Dot{1, 0}},
            DotMatrix{// orientation 1
                Dot{1, 2}, Dot{1, 1}, Dot{2, 1}, Dot{2, 0}},
            DotMatrix{// orientation 2
                Dot{1, 2}, Dot{2, 2}, Dot{0, 1}, Dot{1, 1}},
            DotMatrix{// orientation 3
                Dot{0, 2}, Dot{0, 1}, Dot{1, 1}, Dot{1, 0}}}},
    BlockImpl{COLOR_PAIR(5),
        OrientationMatrix{// T
            DotMatrix{    // orientation 0 (initial)
                Dot{0, 1}, Dot{1, 1}, Dot{2, 1}, Dot{1, 0}},
            DotMatrix{// orientation 1
                Dot{1, 2}, Dot{1, 1}, Dot{2, 1}, Dot{1, 0}},
            DotMatrix{// orientation 2
                Dot{1, 2}, Dot{0, 1}, Dot{1, 1}, Dot{2, 1}},
            DotMatrix{// orientation 3
                Dot{1, 2}, Dot{0, 1}, Dot{1, 1}, Dot{1, 0}}}},
    BlockImpl{COLOR_PAIR(6),
        OrientationMatrix{// J
            DotMatrix{    // orientation 0 (initial)
                Dot{0, 1}, Dot{1, 1}, Dot{2, 1}, Dot{0, 0}},
            DotMatrix{// orientation 1
                Dot{1, 2}, Dot{1, 1}, Dot{1, 0}, Dot{2, 0}},
            DotMatrix{// orientation 2
                Dot{2, 2}, Dot{0, 1}, Dot{1, 1}, Dot{2, 1}},
            DotMatrix{// orientation 3
                Dot{0, 2}, Dot{1, 2}, Dot{1, 1}, Dot{1, 0}}}},
    BlockImpl{COLOR_PAIR(3),
        OrientationMatrix{// S
            DotMatrix{    // orientation 0 (initial)
                Dot{0, 1}, Dot{1, 1}, Dot{1, 0}, Dot{2, 0}},
            DotMatrix{// orientation 1
                Dot{2, 2}, Dot{1, 1}, Dot{2, 1}, Dot{1, 0}},
            DotMatrix{// orientation 2
                Dot{0, 2}, Dot{1, 2}, Dot{1, 1}, Dot{2, 1}},
            DotMatrix{// orientation 3
                Dot{1, 2}, Dot{0, 1}, Dot{1, 1}, Dot{0, 0}}}},
    BlockImpl{COLOR_PAIR(2),
        OrientationMatrix{// L
            DotMatrix{    // orientation 0 (initial)
                Dot{0, 1}, Dot{1, 1}, Dot{2, 1}, Dot{2, 0}},
            DotMatrix{// orientation 1
                Dot{1, 2}, Dot{2, 2}, Dot{1, 1}, Dot{1, 0}},
            DotMatrix{// orientation 2
                Dot{0, 2}, Dot{0, 1}, Dot{1, 1}, Dot{2, 1}},
            DotMatrix{// orientation 3
                Dot{1, 2}, Dot{1, 1}, Dot{0, 0}, Dot{1, 0}}}}};

const Color GetColor(BlockType b)
{
    return blocks[b].GetColor();
}
const char GetChar(BlockType b)
{
    return "OIZTJSL"[int(b)];
}
} // namespace Bastet
