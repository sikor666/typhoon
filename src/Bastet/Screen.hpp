#pragma once

#include "Display.hpp"

#include <memory>
#include <vector>

namespace Bastet
{

class Screen
{
public:
    Screen();
    ~Screen();

    std::vector<int> getKeys();
    const std::unique_ptr<Display> & getDisplay(size_t number) const;

    void refresh();

private:
    Engine _engine;

    int _width;
    int _height;

    std::vector<std::unique_ptr<Display>> _displays;
};

} // namespace Bastet
