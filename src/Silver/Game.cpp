#include "Game.hpp"

namespace Silver
{

Game::Game()
    : _screen{}
    , _map{_screen.getWidth() / 2, _screen.getHeight()}
{
}

Game::~Game()
{
}

void Game::run()
{
    while (true)
    {
        _screen.refresh();
    }
}

} // namespace Silver
