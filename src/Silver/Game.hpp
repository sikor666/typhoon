#pragma once

#include "Bastet/Screen.hpp"

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
};

} // namespace Silver
