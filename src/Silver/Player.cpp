#include "Player.hpp"
#include "Logger.hpp"

namespace Silver
{

Player::Player(const std::string & name)
    : _name{name}
{
}

Player::~Player()
{
}

void Player::push()
{
}

void Player::pop()
{
    dbgW << "Player: " << _name;
}

} // namespace Silver
