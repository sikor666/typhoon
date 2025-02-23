#include "Game.hpp"

#include <algorithm>

namespace Silver
{

Game::Game()
    : _screen{std::make_shared<Bastet::Screen>()}
    , _map{std::make_unique<Map>(_screen)}
{
}

Game::~Game()
{
}

void Game::run()
{
    int x = 10;
    int y = 10;

    _map->push(x, y);

    while (true)
    {
        auto keys = _screen->getKeys();

        if (std::ranges::contains(keys, 'a'))
        {
            _map->move(x, y, x - 1, y);
            x--;
        }
        else if (std::ranges::contains(keys, 'd'))
        {
            _map->move(x, y, x + 1, y);
            x++;
        }
        else if (std::ranges::contains(keys, 's'))
        {
            _map->move(x, y, x, y + 1);
            y++;
        }
        else if (std::ranges::contains(keys, 'w'))
        {
            _map->move(x, y, x, y - 1);
            y--;
        }

        _map->draw(x, y);
    }
}

} // namespace Silver
