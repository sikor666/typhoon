#pragma once

#include <memory>
#include <unordered_map>

namespace Silver
{

class Ship;

class Water
{
public:
    Water(int width, int height);
    ~Water();

    bool push(const std::shared_ptr<Ship> & ship);

private:
    int _width;
    int _height;

    std::unordered_map<int, std::unordered_map<int, std::shared_ptr<Ship>>> _water;
};

} // namespace Silver
