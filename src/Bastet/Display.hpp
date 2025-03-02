#pragma once

#include "Engine.hpp"
#include "Math.hpp"

#include <string>

namespace Bastet
{

class Display
{
public:
    Display(int x, int y, int w, int h, Color color);
    ~Display();

    int width() const;
    int height() const;

    int print(Vector2 position, Color color, const std::string & str);
    int refresh();

private:
    int _width;
    int _height;

    void * _window;
};

} // namespace Bastet
