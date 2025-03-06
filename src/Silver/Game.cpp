#include "Game.hpp"
#include "Bastet/Screen.hpp"
#include "Dice.hpp"
#include "Logger.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Ship.hpp"
#include "Wind.hpp"

#include <algorithm>

namespace Silver {

Game::Game()
    : _screen{std::make_shared<Bastet::Screen>()}
    , _map{std::make_shared<Map>(_screen)}
    , _wind{std::make_shared<Wind>(_screen)}
    , _dice{std::make_shared<Dice>(6)}
{
    _players.push_back(std::make_unique<Player>("computer", _dice));
    _players.push_back(std::make_unique<Player>("pirate", _dice));
    _players.push_back(std::make_unique<Player>("soldier", _dice));

    _players[0]->push([]() { dbgE << "Player computer"; });
    _players[1]->push([]() { dbgE << "Player pirate"; });
    _players[2]->push([]() { dbgE << "Player soldier"; });
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

// Players' turns:
// - ship movements,
// - artillery salvos,
// - ramming,
// - movement of sailors on and off ships,
// - possible declaration of boarding,
// - reloading of silver and cannons

void Game::run()
{
    _wind->setSpeed(_dice->roll());
    _wind->setDirection(Dice{8}.roll() - 1);

    auto caravel = std::make_unique<Ship>(Caravel, Vector2{3, 3}, _map, _wind);
    auto brigantine = std::make_unique<Ship>(Brigantine, Vector2{30, 8}, _map, _wind);

    while (true)
    {
        auto keys = _screen->getKeys();

        if (std::ranges::contains(keys, 'q'))
        {
            break;
        }
        else if (std::ranges::contains(keys, 'a'))
        {
            if (caravel)
                caravel->turnLeft();
        }
        else if (std::ranges::contains(keys, 'd'))
        {
            if (caravel)
                caravel->turnRight();
        }
        else if (std::ranges::contains(keys, 'w'))
        {
            if (caravel)
                caravel->move();
        }
        else if (std::ranges::contains(keys, 's'))
        {
            if (caravel)
                caravel->navigate();
        }
        else if (std::ranges::contains(keys, 'r'))
        {
            if (caravel)
                caravel->drawWindRose();
        }
        else if (std::ranges::contains(keys, 'x'))
        {
            if (caravel)
                caravel.reset();
        }
        else if (std::ranges::contains(keys, 'v'))
        {
            if (not caravel)
                caravel = std::make_unique<Ship>(Caravel, Vector2{3, 3}, _map, _wind);
        }
        else if (std::ranges::contains(keys, 'n'))
        {
            for (const auto & player : _players)
            {
                player->pop();
            }
        }
        else if (std::ranges::contains(keys, 'z'))
        {
            _wind->setDirection((_wind->getDirection() + 1) % 8);
        }
        else if (std::ranges::contains(keys, 'c'))
        {
            _wind->setSpeed((_wind->getSpeed() + 1) % 13);
        }

        _screen->refresh();
    }
}

} // namespace Silver
