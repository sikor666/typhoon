#pragma once

#include "BlockPosition.hpp"

namespace Bastet
{

class Well
{
public:
    Well(int width, int height);

    bool Accommodates(const DotMatrix & d) const;    // true if the given tetromino fits into the well
    void Lock(BlockType t, const BlockPosition & p); // permanently adds a tetromino to the well; returns a bitset of 4
                                                     // bits where return[i]==1 if line (start of fb)+i is complete

private:
    int _width;
    int _height;

    std::vector<std::vector<BlockType>> _well;
};

} // namespace Bastet
