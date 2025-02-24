#include "Engine.hpp"

#include <curses.h>

#include <clocale>
#include <cstdlib>
#include <ctime>

namespace Bastet
{

Engine::Engine()
{
    /* Set the locale to support Unicode */
    setlocale(LC_ALL, "");

    /* Initialize ncurses */
    if (initscr() == nullptr)
    {
        fprintf(stderr, "bastet: error while initializing graphics (ncurses library).\n");
        exit(1);
    }

    if (not has_colors())
    {
        endwin();
        fprintf(stderr, "bastet: no color support, sorry. Ask the author for a black and white version.");
        exit(1);
    }

    /* Turn off cursor. */
    curs_set(0);
    atexit([] { endwin(); }); /*make sure curses are properly stopped*/

    /* Setup keyboard. We'd like to get each and every character, but
       not to display them on the terminal. */
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    nonl();
    noecho();
    cbreak();

    start_color();
    /* 0 - 16 is for blocks */
    init_pair(Color::WhiteBlack, COLOR_WHITE, COLOR_BLACK);
    init_pair(Color::WhiteRed, COLOR_WHITE, COLOR_RED);
    init_pair(Color::WhiteGreen, COLOR_WHITE, COLOR_GREEN);
    init_pair(Color::WhiteYellow, COLOR_WHITE, COLOR_YELLOW);
    init_pair(Color::WhiteBlue, COLOR_WHITE, COLOR_BLUE);
    init_pair(Color::WhiteMagenta, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(Color::WhiteCyan, COLOR_WHITE, COLOR_CYAN);

    /* 17 - ? is for other things */
    init_pair(Color::RedBlack, COLOR_RED, COLOR_BLACK);       // points
    init_pair(Color::GreenBlack, COLOR_GREEN, COLOR_BLACK);   // number of lines
    init_pair(Color::YellowBlack, COLOR_YELLOW, COLOR_BLACK); // level

    /* Set random seed. */
    srandom(time(nullptr) + 37);
}

} // namespace Bastet
