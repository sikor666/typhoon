#include "Curses.hpp"

#include <curses.h>

#include <clocale>
#include <cstdlib>
#include <ctime>

namespace Bastet
{

Curses::Curses()
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
    /* 1 - 16 is for blocks */
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_BLACK, COLOR_CYAN);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(6, COLOR_BLACK, COLOR_BLUE);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

    /* 17 - ? is for other things */
    init_pair(17, COLOR_RED, COLOR_BLACK);    // points
    init_pair(18, COLOR_YELLOW, COLOR_BLACK); // number of lines
    init_pair(19, COLOR_GREEN, COLOR_BLACK);  // level
    init_pair(20, COLOR_YELLOW, COLOR_BLACK); // messages
    init_pair(21, COLOR_WHITE, COLOR_BLACK);  // window borders
    init_pair(22, COLOR_WHITE, COLOR_BLACK);  // end of line animation

    /* Set random seed. */
    srandom(time(nullptr) + 37);
}

} // namespace Bastet
