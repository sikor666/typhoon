#include "Game.hpp"

namespace Silver
{

Game::Game()
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
