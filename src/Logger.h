#pragma once

#include <iostream>
#include <sstream>

// #include <vmo/color.hpp>
namespace vmo
{

constexpr auto yellow  {"\033[33m"};
constexpr auto red     {"\033[91m"};
constexpr auto green   {"\033[92m"};
constexpr auto orange  {"\033[93m"};
constexpr auto blue    {"\033[94m"};
constexpr auto magenta {"\033[95m"};
constexpr auto cyan    {"\033[96m"};
constexpr auto white   {"\033[97m"};
constexpr auto end     {"\033[0m"};

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
        std::cout << mCache.str() << vmo::end << std::endl;
    }

    template <typename T> Logger & operator<<(const T & v)
    {
        mCache << v;
        return *this;
    }
};

#define logE (Logger{} << vmo::red)
#define logW (Logger{} << vmo::yellow)
#define logI (Logger{} << vmo::green)
#define logD (Logger{} << vmo::blue)
