#include "Game.hpp"

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
        _map->draw(x, y);
    }
}

} // namespace Silver
