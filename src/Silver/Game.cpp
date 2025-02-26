#include "Game.hpp"
#include "Bastet/Screen.hpp"
#include "Dice.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Ship.hpp"

#include <algorithm>

namespace Silver
{

Game::Game()
    : _screen{std::make_shared<Bastet::Screen>()}
    , _map{std::make_shared<Map>(_screen)}
    , _dice{std::make_shared<Dice>()}
{
    _players.push(std::make_unique<Player>("computer"));
    _players.push(std::make_unique<Player>("pirate"));
    _players.push(std::make_unique<Player>("soldier"));
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
            if (ship)
                ship->turnLeft();
        }
        else if (std::ranges::contains(keys, 'd'))
        {
            if (ship)
                ship->turnRight();
        }
        else if (std::ranges::contains(keys, 'w'))
        {
            if (ship)
                ship->move();
        }
        else if (std::ranges::contains(keys, 'x'))
        {
            if (ship)
                ship.reset();
        }
        else if (std::ranges::contains(keys, 'v'))
        {
            if (not ship)
                ship = std::make_unique<Ship>(_map);
        }
        else if (std::ranges::contains(keys, 'n'))
        {
            _players.front()->pop();
        }

        _screen->refresh();
    }
}

} // namespace Silver
