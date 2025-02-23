#pragma once

#include "Bastet/Screen.hpp"
#include "Map.hpp"

namespace Silver
{

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    Bastet::Screen _screen;
    Map _map;
};

} // namespace Silver
