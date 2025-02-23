#include "Bastet/Game.hpp"
#include "Logger.hpp"

int main()
{
    try
    {
        Bastet::Game game;
        game.Play();
    }
    catch (std::exception & ex)
    {
        logF << ex.what();
    }

    return 0;
}
