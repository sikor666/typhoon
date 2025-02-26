#include "Dice.hpp"

namespace Silver
{

Dice::Dice()
    : _rd{}
    , _gen{_rd()}
    , _distrib{1, 6}
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
