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
    while (true)
    {
        _screen->refresh();
    }
}

} // namespace Silver
