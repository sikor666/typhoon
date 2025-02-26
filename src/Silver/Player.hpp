#pragma once

#include <string>

namespace Silver
{

class Player
{
public:
    Player(const std::string & name);
    ~Player();

    void push();
    void pop();

private:
    std::string _name;
};

} // namespace Silver
