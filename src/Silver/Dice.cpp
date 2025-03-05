#include "Dice.hpp"

namespace Silver {

Dice::Dice(int sides)
    : _rd{}
    , _gen{_rd()}
    , _distrib{1, sides}
{
}

Dice::~Dice()
{
}

int Dice::roll()
{
    return _distrib(_gen);
}

} // namespace Silver
