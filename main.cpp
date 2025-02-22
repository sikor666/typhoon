#include "Bastet/Engine.hpp"
#include "Bastet/Game.hpp"

int main()
{
    try
    {
        Bastet::Engine curses;
        Bastet::Game game;
        game.Play();
    }
    catch (Bastet::GameOver & go)
    {
    }

    return 0;
}
