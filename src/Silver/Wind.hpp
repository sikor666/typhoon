#pragma once

#include <memory>

namespace Bastet
{

class Screen;

} // namespace Bastet

namespace Silver
{

class Wind
{
public:
    Wind(const std::shared_ptr<Bastet::Screen> & screen);
    ~Wind();

private:
    std::shared_ptr<Bastet::Screen> _screen;

    int _speed;
    int _direction;
};

} // namespace Silver
