#include <locale.h>
#include <ncurses.h>

int main()
{
    setlocale(LC_ALL, ""); // Set the locale to support Unicode
    initscr();             // Initialize ncurses

    wprintw(stdscr, "✓"); // Print Unicode character (checkmark)
    refresh();            // Refresh the screen
    getch();              // Wait for user input

    endwin(); // Cleanup ncurses
    return 0;
}
