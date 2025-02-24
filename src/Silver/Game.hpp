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
    std::shared_ptr<Bastet::Screen> _screen;
    std::shared_ptr<Map> _map;
};

} // namespace Silver
