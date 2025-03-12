#pragma once

#include <memory>
#include <queue>
#include <vector>

namespace Bastet {
class Screen;
} // namespace Bastet

namespace Silver {

class Map;
class Wind;
class Dice;
class Ship;
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
    std::shared_ptr<Wind> _wind;
    std::shared_ptr<Dice> _dice;

    std::queue<std::unique_ptr<Ship>> _ships;
    std::vector<std::unique_ptr<Player>> _players;
};

} // namespace Silver
