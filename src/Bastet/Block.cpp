#include "Block.hpp"

namespace Bastet
{

BlockArray blocks = { // should be yellow, but I find no portable way to output a yellow solid block character in ncurses.
    BlockImpl{WhiteBlack, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},   // O
    BlockImpl{WhiteRed, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},     // I
    BlockImpl{WhiteGreen, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},   // Z
    BlockImpl{WhiteYellow, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},  // T
    BlockImpl{WhiteBlue, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}},    // J
    BlockImpl{WhiteMagenta, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}}, // S
    BlockImpl{WhiteCyan, DotMatrix{Dot{0, 0}, Dot{0, 0}, Dot{0, 0}, Dot{0, 0}}}};   // L

const Color GetColor(BlockType b)
{
    return blocks[b].GetColor();
}
const char GetChar(BlockType b)
{
    return "OIZTJSL"[int(b)];
}
} // namespace Bastet
