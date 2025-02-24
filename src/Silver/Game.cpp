#include "Game.hpp"
#include "Ship.hpp"

#include <algorithm>

namespace Silver
{

Game::Game()
    : _screen{std::make_shared<Bastet::Screen>()}
    , _map{std::make_shared<Map>(_screen)}
{
}

Game::~Game()
{
}

void Game::run()
{
    auto ship = std::make_unique<Ship>(_map);

    while (true)
    {
        auto keys = _screen->getKeys();

        if (std::ranges::contains(keys, 'a'))
        {
            ship->turnLeft();
        }
        else if (std::ranges::contains(keys, 'd'))
        {
            ship->turnRight();
        }
        else if (std::ranges::contains(keys, 'w'))
        {
            ship->move();
        }

        _screen->refresh();
    }
}

} // namespace Silver
