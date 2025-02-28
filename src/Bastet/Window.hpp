#pragma once

#include "Engine.hpp"

#include <string>

namespace Bastet
{

class Window
{
public:
    Window(int x, int y, int w, int h, Color color);
    ~Window();

    int width() const;
    int height() const;

    int print(int x, int y, Color color, const std::string & str);
    int refresh();

private:
    int _width;
    int _height;

    void * _window;
};

} // namespace Bastet
