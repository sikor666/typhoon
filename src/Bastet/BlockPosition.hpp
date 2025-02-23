#pragma once

#include "Block.hpp"

#include <functional>
#include <string>

namespace Bastet
{

/** Block position = position (x,y) + orientation -- this is the object that gets evaluated by the block chooser
 */
class Well;

enum Movement
{
    Left,
    Right,
    Down,
    Up
};

class BlockPosition
{
public:
    Dot _pos;

public:
    BlockPosition(Dot d = (Dot){3, 0})
        : _pos(d)
    {
    }
    bool operator==(const BlockPosition & p) const { return _pos == p._pos; }
    /// returns an y such that the block lies completely in [y,y+3]
    int GetBaseY() const { return _pos.y; }
    void Move(Movement m);
    bool MoveIfPossible(Movement m, BlockType b, const Well & w);

    void Drop(BlockType bt, const Well & w);

    const DotMatrix GetDots(BlockType b) const;
    bool IsValid(BlockType bt, const Well & w) const;
    bool IsOutOfScreen(BlockType bt) const;
};
} // namespace Bastet

// Custom specialization of std::hash can be injected in namespace std.
template <> struct std::hash<Bastet::BlockPosition>
{
    std::size_t operator()(const Bastet::BlockPosition & p) const noexcept { return std::hash<Bastet::Dot>{}(p._pos) * 4; }
};
