#include "static_string.hpp"

#include <iostream>

constexpr auto TEXT0 = literal("static string");
constexpr auto TEXT1 = literal("12345678");
constexpr auto TEXT2 = literal("123456789");

int main()
{
    std::cout << TEXT0 << std::endl;

    auto text = TEXT1 + TEXT2;
    std::cout << text << std::endl;

    string str = TEXT0 + TEXT1 + TEXT2;
    std::cout << str << std::endl;
}