#pragma once

#include "Engine.hpp"

#include <array>
#include <functional>

namespace Bastet
{

struct Dot;
typedef std::array<Dot, 4> DotMatrix;               // the four dots occupied by a tetromino

class BlockImpl;
typedef std::array<BlockImpl, 7> BlockArray;
extern BlockArray blocks;

enum BlockType
{
    O = 0,
    I = 1,
    Z = 2,
    T = 3,
    J = 4,
    S = 5,
    L = 6
};
const size_t nBlockTypes = 7;

struct Dot
{
    int x;
    int y;

    Dot operator+(const Dot & d) const { return Dot{x + d.x, y + d.y}; }
    Dot & operator+=(const Dot & d)
    {
        x += d.x;
        y += d.y;
        return *this;
    }
    DotMatrix operator+(const DotMatrix & b) const
    {
        return (DotMatrix){{*this + b[0], *this + b[1], *this + b[2], *this + b[3]}};
    }
    bool operator==(const Dot & other) const { return x == other.x and y == other.y; }
    bool operator<(const Dot & other) const { return x == other.x ? y < other.y : x < other.x; }
};

class BlockImpl
{
private:
    const DotMatrix _matrix;
    const Color _color;

public:
    BlockImpl(Color c, const DotMatrix & m)
        : _matrix(m)
        , _color(c) {};
    ~BlockImpl() {};
    /**
     * returns an array of 4 (x,y) pair for the occupied dots
     */
    const DotMatrix & GetDotMatrix() { return _matrix; }
    Color GetColor() const { return _color; };
};

// should be members, but BlockType is an enum...
const Color GetColor(BlockType b);
const char GetChar(BlockType b);

} // namespace Bastet

// Custom specialization of std::hash can be injected in namespace std.
template <> struct std::hash<Bastet::Dot>
{
    std::size_t operator()(const Bastet::Dot & d) const noexcept
    {
        return (d.x + 5) * 32 + d.y; // or use boost::hash_combine
    }
};
