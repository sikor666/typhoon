#include "Well.hpp"

#include <cassert>
#include <cstring>
#include <sstream>

namespace Bastet
{

Well::Well(int width, int height)
    : _width{width}
    , _height{height}
{
    _well.resize(_height, std::vector<BlockType>(_width, BlockType::O));
}

bool Well::Accomodates(const DotMatrix & m) const
{
    for (const Dot & d : m)
    {
        if (!d.IsValid(_width, _height) or _well[d.y][d.x] != BlockType::O)
            return false;
    }

    return true;
}

bool Well::IsLineComplete(int y) const
{
    for (int x = 0; x < _width; ++x)
        if (_well[y][x] == BlockType::O)
            return false;

    return true;
}

LinesCompleted Well::Lock(BlockType t, const BlockPosition & p)
{
    if (p.IsOutOfScreen(t))
        throw(GameOver());

    for (const Dot & d : p.GetDots(t))
    {
        _well[d.y][d.x] = t;
    }

    // checks for completedness
    LinesCompleted lc;
    lc._baseY = p.GetBaseY();
    lc._height = _height;

    for (int k = 0; k < 4; ++k)
    {
        int l = lc._baseY + k;

        if (IsValidLine(l) && IsLineComplete(l))
            lc._completed[k] = true;
    }

    return lc;
}

} // namespace Bastet
