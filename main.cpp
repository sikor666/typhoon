#include "Curses.hpp"
#include "Game.hpp"
#include "Ui.hpp"

#include <iostream>

int main()
{
    // Bastet::Ui ui;
    // ui.Play();

    try
    {
        Bastet::Curses curses;
        Bastet::Game game;
        game.Play();
    }
    catch (Bastet::GameOver & go)
    {
    }

    char c;
    std::cin >> c;

    return 0;
}
