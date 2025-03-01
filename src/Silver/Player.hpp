#pragma once

#include <functional>
#include <memory>
#include <queue>
#include <string>

namespace Silver
{

class Dice;

class Player
{
public:
    Player(const std::string & name, const std::shared_ptr<Dice> & dice);
    ~Player();

    void push(std::function<void()> action);
    void pop();

private:
    std::string _name;
    std::shared_ptr<Dice> _dice;

    std::queue<std::function<void()>> _actions;
};

} // namespace Silver
