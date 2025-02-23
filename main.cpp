#include "Bastet/Game.hpp"

int main()
{
    try
    {
        Bastet::Game game;
        game.Play();
    }
    catch (Bastet::GameOver & go)
    {
    }

    return 0;
}
