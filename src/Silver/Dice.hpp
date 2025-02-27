#pragma once

#include <random>

namespace Silver
{

class Dice
{
public:
    Dice(int sides);
    ~Dice();

    int roll();

private:
    std::random_device _rd; // a seed source for the random number engine
    std::mt19937 _gen;      // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> _distrib;
};

} // namespace Silver
