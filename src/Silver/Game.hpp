#pragma once

#include "Bastet/Screen.hpp"
#include "Map.hpp"

#include <queue>

namespace Silver
{

class Player;

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    std::shared_ptr<Bastet::Screen> _screen;
    std::shared_ptr<Map> _map;

    std::queue<std::unique_ptr<Player>> _players;
};

} // namespace Silver
