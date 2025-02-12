#include "Logger.h"

#include <ncurses.h>

#include <iomanip>

int main()
{
    // init screen and sets up screen
    initscr();

    const int height = 31;
    const int width = 61;

    std::stringstream ss;

    ss << "  ";

    for (int x = 0; x < width; x++)
    {
        auto color = x % 2 ? vmo::magenta : vmo::cyan;

        ss << color << std::setfill('0') << std::setw(2) << x << vmo::end;
    }

    ss << '\n';

    for (int y = 0; y < height; y++)
    {
        auto color = y % 2 ? vmo::magenta : vmo::cyan;

        ss << color << std::setfill('0') << std::setw(2) << y << vmo::end;

        for (int x = 0; x < width; x++)
        {
            ss << ' ' << '+';
        }

        ss << '\n';
    }

    // print to screen
    printw(ss.str().c_str());

    // refreshes the screen
    refresh();

    // pause the screen output
    getch();

    // deallocates memory and ends ncurses
    endwin();

    return 0;
}
