#pragma once

#include <iostream>
#include <sstream>

// #include <vmo/color.hpp>
namespace vmo
{

constexpr auto YELLOW  {"\033[33m"};
constexpr auto RED     {"\033[91m"};
constexpr auto GREEN   {"\033[92m"};
constexpr auto ORANGE  {"\033[93m"};
constexpr auto BLUE    {"\033[94m"};
constexpr auto MAGENTA {"\033[95m"};
constexpr auto CYAN    {"\033[96m"};
constexpr auto WHITE   {"\033[97m"};
constexpr auto END     {"\033[0m"};

} // namespace vmo

class Logger
{
private:
    std::stringstream mCache;

public:
    Logger() = default;

    ~Logger()
    {
        // flush on destroy
        std::cout << mCache.str() << vmo::END << std::endl;
    }

    template <typename T> Logger & operator<<(const T & v)
    {
        mCache << v;
        return *this;
    }
};

#define logE (Logger{} << vmo::RED)
#define logW (Logger{} << vmo::YELLOW)
#define logI (Logger{} << vmo::GREEN)
#define logD (Logger{} << vmo::BLUE)
