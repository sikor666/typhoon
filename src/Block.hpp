#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <array>
#include <functional>

namespace Bastet
{

typedef int Color; // to be given to wattrset

struct Dot;
typedef std::array<Dot, 4> DotMatrix;               // the four dots occupied by a tetromino
typedef std::array<DotMatrix, 4> OrientationMatrix; // the four orientations of a tetromino

class BlockImpl;
typedef std::array<BlockImpl, 7> BlockArray;
extern BlockArray blocks;

class Orientation
{
public:
    Orientation(unsigned char o = 0)
        : _o(o)
    {
    }
    operator unsigned char() const { return _o; }
    Orientation operator++() { return (++_o & 3); }
    Orientation Next() const { return ((_o + 1) & 3); }
    Orientation operator--() { return (--_o & 3); }
    Orientation Prior() const { return ((_o - 1) & 3); }
    const static size_t Number = 4;

private:
    unsigned char _o;
};

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
    bool IsValid(int width, int height) const { return (y >= 0) and y < height and (x >= 0) and (x < width); }

    Dot operator+(const Dot & d) const { return (Dot){x + d.x, y + d.y}; }
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
    bool operator==(const Dot & other) const { return (x == other.x) and (y == other.y); }
    bool operator<(const Dot & other) const
    {
        if (x == other.x)
            return y < other.y;
        else
            return x < other.x;
    }
};

class BlockImpl
{
private:
    const OrientationMatrix _matrix;
    const Color _color;

public:
    BlockImpl(Color c, const OrientationMatrix & m)
        : _matrix(m)
        , _color(c) {};
    ~BlockImpl() {};
    /**
     * returns an array of 4 (x,y) pair for the occupied dots
     */
    const OrientationMatrix & GetOrientationMatrix() { return _matrix; }
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

#endif // BLOCK_HPP
