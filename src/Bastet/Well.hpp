#pragma once

#include "Block.hpp" //for Color
#include "BlockPosition.hpp"

#include <array>
#include <bitset>
#include <cstddef> //size_t
#include <vector>

namespace Bastet
{

class GameOver
{
}; // used as an exception

/*
 * the real height of the well is _height+2, with the top two rows( -1 and -2) hidden (see guidelines)
 */
class Well
{
public:
    Well(int width, int height);

    bool Accomodates(const DotMatrix & d) const; // true if the given tetromino fits into the well
    void Lock(BlockType t, const BlockPosition & p); // permanently adds a tetromino to the well; returns a bitset of 4
                                                     // bits where return[i]==1 if line (start of fb)+i is complete

private:
    int _width;
    int _height;

    std::vector<std::vector<BlockType>> _well;
};

} // namespace Bastet
