#include "Water.hpp"

namespace Silver
{

Water::Water(int width, int height)
    : _width{width}
    , _height{height}
{
    _water.resize(_height, std::vector<int>(_width, 0));
}

Water::~Water()
{
}

} // namespace Silver
