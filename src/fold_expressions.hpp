#include <climits>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

template <typename... Args> void printer(Args &&... args)
{
    (std::cout << ... << args) << '\n';
}

template <typename T, typename... Args> void push_back_vec(std::vector<T> & v, Args &&... args)
{
    static_assert((std::is_constructible_v<T, Args &&> && ...));
    (v.push_back(std::forward<Args>(args)), ...);
}

template <class T, std::size_t... dummy_pack> constexpr T bswap_impl(T i, std::index_sequence<dummy_pack...>)
{
    T low_byte_mask = (unsigned char)-1;
    T ret{};
    (
        [&] {
            (void)dummy_pack;
            ret <<= CHAR_BIT;
            ret |= i & low_byte_mask;
            i >>= CHAR_BIT;
        }(),
        ...);
    return ret;
}

constexpr auto bswap(std::unsigned_integral auto i)
{
    return bswap_impl(i, std::make_index_sequence<sizeof(i)>{});
}
