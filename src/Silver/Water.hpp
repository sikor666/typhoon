#pragma once

#include <vector>

namespace Silver
{

class Water
{
public:
    Water(int width, int height);
    ~Water();

private:
    int _width;
    int _height;

    std::vector<std::vector<int>> _water;
};

} // namespace Silver
