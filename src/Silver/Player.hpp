#pragma once

#include <memory>
#include <string>

namespace Silver
{

class Dice;

class Player
{
public:
    Player(const std::string & name, const std::shared_ptr<Dice> & dice);
    ~Player();

    void push();
    void pop();

private:
    std::string _name;
    std::shared_ptr<Dice> _dice;
};

} // namespace Silver
