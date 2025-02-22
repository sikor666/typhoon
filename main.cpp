#include "Curses.hpp"
#include "Game.hpp"

int main()
{
    try
    {
        Bastet::Curses curses;
        Bastet::Game game;
        game.Play();
    }
    catch (Bastet::GameOver & go)
    {
    }

    return 0;
}
