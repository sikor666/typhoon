#pragma once

#include "Engine.hpp"

#include <string>
#include <vector>

namespace Bastet
{

class Screen
{
public:
    Screen();
    ~Screen();

    int getWidth() const;
    int getHeight() const;

    std::vector<int> getKeys();

    int draw(int x, int y, const std::string & str, Color color);
    void refresh();

protected:
    int draw(int x, int y, const std::string & str, void * screen);

private:
    Engine _engine;

    int _width;
    int _height;

    void * _window;
    void * _panel;
};

} // namespace Bastet
