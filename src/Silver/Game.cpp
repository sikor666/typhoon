#include "Game.hpp"
#include "Bastet/Screen.hpp"
#include "Dice.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Ship.hpp"
#include "Wind.hpp"

#include <algorithm>

namespace Silver
{

Game::Game()
    : _screen{std::make_shared<Bastet::Screen>()}
    , _map{std::make_shared<Map>(_screen)}
    , _dice{std::make_shared<Dice>(6)}
{
    _players.push_back(std::make_unique<Player>("computer", _dice));
    _players.push_back(std::make_unique<Player>("pirate", _dice));
    _players.push_back(std::make_unique<Player>("soldier", _dice));
}

Game::~Game()
{
}

// [X] Direction factor:
// (7)       (0)       (1)
//     7.0         7.0
//         🡮  🡫  🡯
// (6) 6.0 🡪  🢁 🡨 6.0 (2)
//         🡭  🡩  🡬
//     5.0   3.5   5.0
// (5        (4)       (3)
//
// [A] Wind force:              6
// [B] Wind direction:          1
// [C] Average speed (current): 9
// [D] Ship's maneuverability:  2
// [E] Ship direction:          0

//    (A + C) / X
// 0: (6 + 9) / 3.5 = 4.3
// 1: (6 + 9) / 5.0 = 3.0
// 2: (6 + 9) / 6.0 = 2.5
// 3: (6 + 9) / 7.0 = 2.1
// 4: (6 + 9) / !!! =
// 5: (6 + 9) / 7.0 = 2.1
// 6: (6 + 9) / 6.0 = 2.5
// 7: (6 + 9) / 5.0 = 3.0

// 🢀 🢁 🢂 🢃 🢄 🢅 🢆 🢇


void Game::run()
{
    auto wind = std::make_unique<Wind>(_screen);
    auto ship = std::make_unique<Ship>(_map);

    while (true)
    {
        auto keys = _screen->getKeys();

        if (std::ranges::contains(keys, 'q'))
        {
            break;
        }
        else if (std::ranges::contains(keys, 'a'))
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
            for (const auto & player : _players)
            {
                player->pop();
            }
        }
        else if (std::ranges::contains(keys, 'e'))
        {
            wind->setSpeed(6);
            wind->setDirection(1);
        }

        _screen->refresh();
    }
}

} // namespace Silver
