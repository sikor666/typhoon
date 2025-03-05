#include "Player.hpp"
#include "Dice.hpp"
#include "Logger.hpp"

namespace Silver {

Player::Player(const std::string & name, const std::shared_ptr<Dice> & dice)
    : _name{name}
    , _dice{dice}
{
}

Player::~Player()
{
}

void Player::push(std::function<void()> action)
{
    _actions.push(action);
}

void Player::pop()
{
    dbgW << "Roll [" << _name << "][" << _dice->roll() << "]";

    while (not _actions.empty())
    {
        _actions.front()();
        _actions.pop();
    }
}

} // namespace Silver
