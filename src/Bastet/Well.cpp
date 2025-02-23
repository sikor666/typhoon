#include "Well.hpp"

#include <stdexcept>

namespace Bastet
{

Well::Well(int width, int height)
    : _width{width}
    , _height{height}
{
    _well.resize(_height, std::vector<BlockType>(_width, BlockType::O));
}

bool Well::Accommodates(const DotMatrix & m) const
{
    for (const auto & d : m)
    {
        bool isValid = d.y >= 0 and d.y < _height and d.x >= 0 and d.x < _width;

        if (not isValid or _well[d.y][d.x] != BlockType::O)
            return false;
    }

    return true;
}

void Well::Lock(BlockType t, const BlockPosition & p)
{
    if (p.IsOutOfScreen(t))
        throw std::runtime_error{"Position is out of screen"};

    for (const auto & d : p.GetDots(t))
    {
        _well[d.y][d.x] = t;
    }
}

} // namespace Bastet
