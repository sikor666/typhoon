#include "Logger.h"

#include <iomanip>

int main()
{
    const int height = 31;
    const int width = 61;

    std::cout << "  ";

    for (int x = 0; x < width; x++)
    {
        auto color = x % 2 ? vmo::magenta : vmo::cyan;

        std::cout << color << std::setfill('0') << std::setw(2) << x << vmo::end;
    }

    std::cout << '\n';

    for (int y = 0; y < height; y++)
    {
        auto color = y % 2 ? vmo::magenta : vmo::cyan;

        std::cout << color << std::setfill('0') << std::setw(2) << y << vmo::end;

        for (int x = 0; x < width; x++)
        {
            std::cout << ' ' << '+';
        }

        std::cout << '\n';
    }
}
