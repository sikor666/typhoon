#include "BlockPosition.hpp"

#include "Block.hpp"
#include "Well.hpp"

namespace Bastet
{
const DotMatrix BlockPosition::GetDots(BlockType b) const
{
    return DotMatrix{_pos, _pos, _pos, _pos};
    // return _pos + ((blocks[b].GetOrientationMatrix())[_orientation]);
}

void BlockPosition::Move(Movement m)
{
    switch (m)
    {
        case RotateCW: _orientation = _orientation.Next(); break;
        case RotateCCW: _orientation = _orientation.Prior(); break;
        case Left: _pos.x -= 1; break;
        case Right: _pos.x += 1; break;
        case Down: _pos.y += 1; break;
        case Up: _pos.y -= 1; break;
    }
}

bool BlockPosition::MoveIfPossible(Movement m, BlockType b, const Well & w)
{
    BlockPosition p{*this};
    p.Move(m);

    if (p.IsValid(b, w))
    {
        *this = p;
        return true;
    }
    else
        return false;
}

bool BlockPosition::IsValid(BlockType bt, const Well & w) const
{
    return w.Accommodates(GetDots(bt)); // XX: must change, unoptimized
}

void BlockPosition::Drop(BlockType bt, const Well & w)
{
    while (MoveIfPossible(Down, bt, w))
        ;
}

bool BlockPosition::IsOutOfScreen(BlockType bt) const
{
    for (const Dot & d : GetDots(bt))
    {
        if (d.y >= 0)
            return false;
    }
    return true;
}

} // namespace Bastet
