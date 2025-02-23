#pragma once

#include <memory>
#include <unordered_map>

namespace Bastet
{

class Screen;

} // namespace Bastet

namespace Silver
{

class Ship;

class Map
{
public:
    Map(const std::shared_ptr<Bastet::Screen> & screen);
    ~Map();

    bool push(const std::shared_ptr<Ship> & ship);

private:
    std::shared_ptr<Bastet::Screen> _screen;
    std::unordered_map<int, std::unordered_map<int, std::shared_ptr<Ship>>> _water;

    const int _width;
    const int _height;
};

} // namespace Silver
