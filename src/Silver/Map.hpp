#pragma once

#include <memory>
#include <vector>

namespace Bastet
{

class Screen;

} // namespace Bastet

namespace Silver
{

class Map
{
public:
    Map(const std::shared_ptr<Bastet::Screen> & screen);
    ~Map();

    void push(int x, int y);

private:
    std::shared_ptr<Bastet::Screen> _screen;
    std::vector<std::vector<bool>> _water;

    const int _width;
    const int _height;
};

} // namespace Silver
