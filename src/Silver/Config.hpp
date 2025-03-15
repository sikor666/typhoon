#pragma once

#include <cmath>

namespace Silver {

constexpr auto NUM_DIRECTIONS = 8u;
constexpr auto NUM_ARROW_STYLES = 2u;

const auto SIDE_LEN = 1.0;
const auto DIAG_LEN = std::sqrt(SIDE_LEN * SIDE_LEN * 2.0);

} // namespace Silver
