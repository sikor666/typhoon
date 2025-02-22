#include "Bastet/Curses.hpp"
#include "Bastet/Game.hpp"

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
