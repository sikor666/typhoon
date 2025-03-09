#pragma once

#include "Math.hpp"

#include <memory>
#include <vector>

namespace Bastet {
class Screen;
} // namespace Bastet

namespace Silver {

class Map
{
public:
    Map(const std::shared_ptr<Bastet::Screen> & screen);
    ~Map();

    void push(const Vector2 & pos, const std::string & str);
    void pop(const Vector2 & pos);
    void update(const Vector2 & pos, const std::string & str);
    Vector2 move(const Vector2 & pos, int direction, const std::string & str);
    std::vector<Vector2> show(const std::vector<Vector2> & pos, const std::string & str);

protected:
    bool valid(int x, int y);

private:
    std::shared_ptr<Bastet::Screen> _screen;
    std::vector<std::vector<bool>> _water;

    const int _width;
    const int _height;
};

} // namespace Silver
